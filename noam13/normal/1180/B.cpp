#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
//#define abs(a) ((a)>0?a:-(a))
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;

int absF(int x){
    if(x>=0) return x;
    return -x-1;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    if (n%2==0){
        int x;
        loop(i,0,n){
            cin>>x;
            if (x<0) cout<<x<<" ";
            else cout<<(-x-1)<<" ";
        }
    }
    else{
        vi arr(n);
        ii m={0,0};
        loop(i,0,n){
            cin>>arr[i];
            arr[i]=absF(arr[i]);
            chkmax( m , make_pair(arr[i],i) );
        }
        loop(i,0,n){
            if (i==m.y){
                cout<<arr[i]<<" ";
            }
            else{
                cout<<(-arr[i]-1)<<" ";
            }
        }
    }
    cout<<endl;
    return 0;
}