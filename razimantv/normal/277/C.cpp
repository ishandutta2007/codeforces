# include <cstdio>
# include <vector>
# include <algorithm>
# include <vector>

using namespace std;

struct pos
{
    int c,x,type;
    bool operator<(const pos&p)const
    {
        return ((c!=p.c)?(c<p.c):(x<p.x));
    }
}x[200000],y[200000];

struct two
{
    int len,coord;
    two(int a=0,int b=0)
    {
        len=a,coord=b;
    }
};
vector<two> xvec,yvec;

int main()
{
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);

    int xnum=0,ynum=0;
    for(int i=0;i<K;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a==c)
        {
            if(b>d)swap(b,d);
            x[xnum].c=a;
            x[xnum].x=b;
            x[xnum++].type=1;
            x[xnum].c=a;
            x[xnum].x=d;
            x[xnum++].type=2;
        }
        else if(b==d)
        {
            if(a>c)swap(a,c);
            y[ynum].c=b;
            y[ynum].x=a;
            y[ynum++].type=1;
            y[ynum].c=b;
            y[ynum].x=c;
            y[ynum++].type=2;
        }
    }
    sort(x,x+xnum);
    sort(y,y+ynum);

    int longest=0,longesttype=0,longestcoord=0,ret=0;
    int xbad=0,ybad=0,xrem=0,yrem=0;
    for(int i=0,j;i<xnum;)
    {
        for(j=i+1;j<xnum&&x[j].c==x[i].c;j++);
        int len=0,lastpos=0,type=0;
        for(int k=i;k<j;k++)
        {
            if(x[k].type==1)
            {
                if(type++==0)len+=x[k].x-lastpos;
            }
            else type--;
            lastpos=x[k].x;
        }
        len+=M-lastpos;
        if(len>longest)
        {
            longest=len;
            longesttype=1;
            longestcoord=x[i].c;
        }
        ret^=len;
        xvec.push_back(two(len,x[i].c));
        i=j;
        xbad++;
    }
    xrem=N-1-xbad;
    if(xrem!=0)
    {
        if(M>longest)
        {
            longest=M;
            longesttype=1;
            if(x[0].c!=1)
            {
                longestcoord=1;
                xvec.push_back(two(M,1));
            }
            else
            {
                longestcoord=-1;
                for(int i=1;i<xnum;i++)
                    if(x[i].c>x[i-1].c+1)
                    {
                        longestcoord=x[i-1].c+1;
                        xvec.push_back(two(M,x[i-1].c+1));
                        break;
                    }
                if(longestcoord==-1)
                {
                    longestcoord=N-1;
                    xvec.push_back(two(M,N-1));
                }
            }
        }
        if(xrem&1)ret^=M;
    }

    for(int i=0,j;i<ynum;)
    {
        for(j=i+1;j<ynum&&y[j].c==y[i].c;j++);
        int len=0,lastpos=0,type=0;
        for(int k=i;k<j;k++)
        {
            if(y[k].type==1)
            {
                if(type++==0)len+=y[k].x-lastpos;
            }
            else type--;
            lastpos=y[k].x;
        }
        len+=N-lastpos;
        if(len>longest)
        {
            longest=len;
            longesttype=2;
            longestcoord=y[i].c;
        }
        ret^=len;
        yvec.push_back(two(len,y[i].c));
        i=j;
        ybad++;
    }
    yrem=M-1-ybad;
    if(yrem!=0)
    {
        if(N>longest)
        {
            longest=N;
            longesttype=2;
            if(y[0].c!=1)
            {
                longestcoord=1;
                yvec.push_back(two(N,1));
            }
            else
            {
                longestcoord=-1;
                for(int i=1;i<ynum;i++)
                    if(y[i].c>y[i-1].c+1)
                    {
                        longestcoord=y[i-1].c+1;
                        yvec.push_back(two(N,longestcoord));
                        break;
                    }
                if(longestcoord==-1)
                {
                    longestcoord=M-1;
                    yvec.push_back(two(N,M-1));
                }
            }
        }
        if(yrem&1)ret^=N;
    }

    if(ret==0)
    {
        printf("SECOND\n");
        return 0;
    }

    printf("FIRST\n");
    for(int i=0;i<xvec.size();i++)
    {
        if((ret^xvec[i].len)>xvec[i].len)continue;
	if(xvec[i].len==M)
        {
            printf("%d %d %d %d\n",xvec[i].coord,0,xvec[i].coord,M-(xvec[i].len^ret));
            return 0;
        }
        int torem=xvec[i].len-(ret^xvec[i].len);
        for(int j=0,k;j<xnum;j++)
        {
            if(x[j].c!=xvec[i].coord)continue;
            for(k=j+1;k<xnum&&x[j].c==x[k].c;k++);
            int len=0,lastpos=0,type=0;
            for(int l=j;l<k;l++)
            {
                if(x[l].type==1)
                {
                    if(type++==0)
                    {
                        if(len+x[l].x-lastpos>=torem)
                        {
                            printf("%d %d %d %d\n",xvec[i].coord,0,xvec[i].coord,lastpos+torem-len);
                            return 0;
                        }
                        len+=x[l].x-lastpos;
                    }
                }
                else type--;
                lastpos=x[l].x;
            }
            printf("%d %d %d %d\n",xvec[i].coord,0,xvec[i].coord,lastpos+torem-len);
            return 0;
        }
    }
    for(int i=0;i<yvec.size();i++)
    {
        if((ret^yvec[i].len)>yvec[i].len)continue;
        if(yvec[i].len==N)
        {
            printf("%d %d %d %d\n",0,yvec[i].coord,N-(yvec[i].len^ret),yvec[i].coord);
            return 0;
        }
        int torem=yvec[i].len-(ret^yvec[i].len);
        for(int j=0,k;j<ynum;j++)
        {
            if(y[j].c!=yvec[i].coord)continue;
            for(k=j+1;k<ynum&&y[j].c==y[k].c;k++);
            int len=0,lastpos=0,type=0;
            for(int l=j;l<k;l++)
            {
                if(y[l].type==1)
                {
                    if(type++==0)
                    {
                        if(len+y[l].x-lastpos>=torem)
                        {
                            printf("%d %d %d %d\n",0,yvec[i].coord,lastpos+torem-len,yvec[i].coord);
                            return 0;
                        }
                        len+=y[l].x-lastpos;
                    }
                }
                else type--;
                lastpos=y[l].x;
            }
            printf("%d %d %d %d\n",0,yvec[i].coord,lastpos+torem-len,yvec[i].coord);
            return 0;
        }
    }
    return 0;
}