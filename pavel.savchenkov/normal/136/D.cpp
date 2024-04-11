    #pragma comment (linker, "/STACK:200000000")
    #include <cstdio>
    #include <iostream>
    #include <algorithm>
    #include <cstring>
    #include <vector>
    #include <bitset>
    #include <math.h>
    #define pb push_back
    #define eps 1e-9
    using namespace std;

    struct coord { double x,y;};
    coord t[8];

    bool cmp1(coord a,coord b) {
            if (a.x<b.x) return true;
             else if (a.x>b.x) return false;
            return a.y<b.y;
    }

    bool cmp2(coord a,coord b) {
            return atan2(a.y,a.x)<atan2(b.y,b.x);
    }

    double len(coord a,coord b) {
            return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
    }

    bool ok(double a,double b) {
            if (fabs(a-b)<eps) return true;
            return false;
    }

    bool sqr(int i,int j,int k,int z) {
            coord g[4];
            g[0]=t[i]; g[1]=t[j]; g[2]=t[k]; g[3]=t[z];
            sort(g,g+4,cmp1);
            for (int i=1;i<4;i++) g[i].x-=g[0].x,g[i].y-=g[0].y;
            g[0].x=g[0].y=0;
            sort(g+1,g+4,cmp2);
            if (!( ok(len(g[0],g[1]),len(g[1],g[2])) && ok(len(g[1],g[2]),len(g[2],g[3])) && ok(len(g[2],g[3]),len(g[3],g[9])) ))
                    return false;
            if ( ok(g[1].x*g[3].x+g[1].y*g[3].y,0) ) return true; else return false;
            for (int i=0;i<4;i++) cout<<g[i].x<<" "<<g[i].y<<endl;
    }

    bool pu (int i,int j,int k,int z) {
            coord g[4];
            g[0]=t[i]; g[1]=t[j]; g[2]=t[k]; g[3]=t[z];
            sort(g,g+4,cmp1);
            for (int i=1;i<4;i++) g[i].x-=g[0].x,g[i].y-=g[0].y;
            g[0].x=g[0].y=0;
            sort(g+1,g+4,cmp2);
            if (!( ok(len(g[0],g[1]),len(g[3],g[2])) && ok(len(g[1],g[2]),len(g[0],g[3])) ))
                    return false;
            if ( ok(g[1].x*g[3].x+g[1].y*g[3].y,0) ) return true; else return false;
            for (int i=0;i<4;i++) cout<<g[i].x<<" "<<g[i].y<<endl;
    }

    int main() {
       //freopen("input.txt","r",stdin);
      // freopen("output.txt","w",stdout);
        bitset <8> mask;
       for (int i=0;i<8;i++) scanf("%lf%lf",&t[i].x,&t[i].y);
       for (int i=0;i<8;i++)
               for (int j=i+1;j<8;j++)
                       for (int k=j+1;k<8;k++)
                               for (int z=k+1;z<8;z++)
                               { mask=0;
                                     mask[i]=1; mask[j]=1; mask[k]=1; mask[z]=1;
                                     vector <int> g;
                                     for (int a=0;a<8;a++)
                                             if (mask[a]==0) g.pb(a);
                                     if (sqr(i,j,k,z)&&pu(g[0],g[1],g[2],g[3]))
                                     {
                                             cout<<"YES"<<endl;
                                            cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<z+1<<endl;
                                            cout<<g[0]+1<<" "<<g[1]+1<<" "<<g[2]+1<<" "<<g[3]+1;
                                            return 0;
                                     }
                               }
        cout<<"NO";
       return 0;
    }