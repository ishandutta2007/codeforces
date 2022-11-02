#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;
int x[300007];
int y[300007];
int mnOX[2500007];
int mnOY[2500007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=2500000;i++)
        {
            mnOX[i]=inf;
            mnOY[i]=inf;
        }
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            for(auto a:s)
            {
                if(a=='B') x[i]++;
                else y[i]++;
            }
          //  cout<<x[i]<<" "<<y[i]<<endl;
            mnOX[x[i]]=min(mnOX[x[i]],y[i]);
            mnOY[y[i]]=min(mnOY[y[i]],x[i]);
        }
        int mnX=1;
        for(int i=2;i<=n;i++) if(mp(x[mnX],y[mnX])>mp(x[i],y[i])) mnX=i;
        //cout<<x[mnX]<<" "<<y[mnX]<<endl;
        int l=0,r=1000000,sr,ans=0,B=0,N=0,tB,tN;
        while(l<=r)
        {
            sr=(l+r)/2;
            int shift_down=0,shift_left=0;
            bool ok=1;
            for(int i=x[mnX];i<=x[mnX]+sr;i++) shift_down=max(shift_down,y[mnX]-mnOX[i]);
            for(int i=x[mnX]+sr+1;i<=x[mnX]+2*sr;i++) shift_down=max(shift_down,y[mnX]+(i-x[mnX]-sr)-mnOX[i]);
            for(int i=y[mnX]-shift_down+sr+1;i<=y[mnX]-shift_down+2*sr;i++) shift_left=max(shift_left,x[mnX]+(i+shift_down-y[mnX]-sr)-mnOY[i]);
            tB=x[mnX]+sr-shift_left;
            tN=y[mnX]+sr-shift_down;
            for(int i=1;i<=n;i++)
            {
                if((x[i]>=tB&&y[i]>=tN)||(x[i]<=tB&&y[i]<=tN))
                {
                    if(max(abs(x[i]-tB),abs(y[i]-tN))>sr) ok=0;
                }
                else if(abs(x[i]-tB)+abs(y[i]-tN)>sr) ok=0;
            }
            if(ok)
            {
                ans=sr;
                B=tB;
                N=tN;
                r=sr-1;
            }
            else l=sr+1;
        }
        cout<<ans<<endl;
        while(B--) cout<<'B';
        while(N--) cout<<'N';
    }

    return 0;
}