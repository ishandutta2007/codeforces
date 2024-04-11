#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,int>
#define x first
#define y second
#define abs(x) ((x>0)?(x):(-x))
#define all(x) x.begin(), x.end()
using namespace std;
const int INF=1e18;

vector<vi> c;
vi p;
vi res;




int32_t main(){
    int n,a,b;cin>>n;
    c.resize(n);
    p.resize(n);
    res.resize(n);
    for(int i=0;i<n;i++){
        cin >> a >>b;a--;
        if (a!=-2){
            p[i]=a;
            c[a].pb(i);
        }
        res[i]=b;
    }
    //for (int i=0;i<n;i++) cout<<res[i]<<" ";
    //cout<<endl<<endl;
    bool bo;
    vi ans;
    for(int i=0;i<n;i++){
        if (res[i]==0) continue;
        bo=true;
        //cout<< 1+i <<":  ";
        for(auto ch: c[i]){
            //cout << 1+c[i][j]<<"-"<<res[c[i][j]] << "  ";
            if (res[ch]==0) bo=false;
        }
        //cout<<endl;
        if (bo){
            /*for(int j=0;j<c[i].size();j++){
                c[p[i]].pb(c[i][j]);
                p[j]=p[i];
            }*/
            ans.pb(i+1);
        }
    }
    if (ans.size()>0) for(int i=0;i<ans.size();i++) cout<< ans[i]<<" ";
    else cout<<-1;
    cout <<endl;
    return 0;
}