#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n;
    vector<string> a(n);
    loop(i,0,n){
        cin >> a[i];
    }
    cin >> m;
    vi p(m);
    loop(i,0,m) cin>>p[i],p[i]--;
    vi ans(1,p[0]);
    vector<vi> dist(n,vi(n,INF));
    loop(i,0,n){
        loop(j,0,n){
            if (a[i][j]=='1') dist[i][j]=1;
        }
    }
    loop(k,0,n){
        loop(i,0,n){
            loop(j,0,n){
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    loop(i,0,n) dist[i][i]=0;
    /*loop(i,0,n){
        loop(j,0,n) cout<<dist[i][j] <<" ";
        cout<<endl;
    }*/
    int last=0;
    //cout<<dist[3][0]<<endl;
    loop(i,1,m){
        //if (last!=4) cout<<"MOVE: ";
        while(i<m && dist[p[last]][p[i]]==i-last) {
            i++;
            //cout<< i<<" ";
            //if (p[i]==p[last]) last=i++;
        }
        //if(last!=4) cout<<endl;
        i--;
        ans.pb(p[i]);
        //if(last!=4) cout<<p[i]<<endl;
        //if (last!=4) cout<<"I"<<i<<" "<<last<<endl;
        last = i;

    }
    cout<<ans.size()<<endl;
    loop(i,0,ans.size()) cout<< (ans[i]+1) <<" ";

    return 0;
}