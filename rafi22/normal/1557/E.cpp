#include <bits/stdc++.h>

#define int long long
#define ld long double
#define double long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int x,y,dx,dy;
int pdx,pdy;

bool pos[10][10];

int cnt=0;

bool Move()
{
    cnt++;
    if(cnt>130) exit(1);
    string s;
    cin>>s;
    if(s=="Right") dy++;
    if(s=="Left") dy--;
    if(s=="Up") dx--;
    if(s=="Down") dx++;
    if(s=="Down-Right")
    {
        dx++;
        dy++;
    }
    if(s=="Down-Left")
    {
        dx++;
        dy--;
    }
    if(s=="Up-Left")
    {
        dx--;
        dy--;
    }
    if(s=="Up-Right")
    {
        dx--;
        dy++;
    }
    if(s=="Done") return 0;
    return 1;
}

bool good(int X,int Y)
{
    return (X>0&&X<=8&&Y>0&&Y<=8);
}
bool reachable(int X,int Y,int X1,int Y1)
{
    return (X==X1||Y==Y1||X+Y==X1+Y1||X-Y==X1-Y1);
}


bool matuj(int X,int Y)
{
    if(max(1LL,X-1)!=x) cout<<max(1LL,X-1)<<" "<<y<<endl;
    else
    {
        if(y==1)
        {
            cout<<x<<" "<<y+1<<endl;
            y++;
        }
        else
        {
            cout<<x<<" "<<y-1<<endl;
            y--;
        }

    }
    x=max(1LL,X-1);
    while(true)
    {
        pdx=dx;
        pdy=dy;
        if(!Move()) return 1;
        if(x==8) break;
        X=X+dx-pdx;
        Y=Y+dy-pdy;
        if(!good(X,Y)||reachable(X,Y,x,y)) return 0;
        if(reachable(x,y,X-1,Y))
        {
            cout<<X-1<<" "<<Y<<endl;
            x=X-1;
            y=Y;
        }
        else
        {
            cout<<x+1<<" "<<y<<endl;
            x++;
        }
    }
    return 0;
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int cd=0;
        cnt=0;
        memset(pos,0,sizeof pos);
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
            {
                pos[i][j]=1;
                cd++;
            }
        }
        pos[4][4]=0;
        x=4,y=4;
        cout<<x<<" "<<y<<endl;
        dx=0,dy=0;
        bool nie=0;
        while(true)
        {
            if(!Move())
            {
                nie=1;
                break;
            }
            for(int i=1;i<=8;i++)
            {
                for(int j=1;j<=8;j++)
                {
                    if(pos[i][j]&&!good(i+dx,j+dy))
                    {
                        pos[i][j]=0;
                        cd--;
                    }
                    if(reachable(x,y,i,j))
                    {
                        if(good(i-dx,j-dy)&&pos[i-dx][j-dy])
                        {
                            pos[i-dx][j-dy]=0;
                            cd--;
                        }
                    }
                }
            }
            if(cd<=5) break;
            while(true)
            {
                int nx=rand()%8+1,ny=rand()%8+1;
                if((x!=nx||y!=ny)&&reachable(x,y,nx,ny))
                {
                    x=nx;
                    y=ny;
                    cout<<x<<" "<<y<<endl;
                    break;
                }
            }
        }
        if(cnt>20) exit(1);
        if(nie) continue;
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
            {
                if(pos[i][j]&&good(i+dx,j+dy))
                {
                    if(matuj(i+dx,j+dy)) nie=1;
                }
                if(nie) break;
            }
            if(nie) break;
        }
        if(nie) continue;
        exit(1);
    }

    return 0;
}