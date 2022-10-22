#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define chkmin(a,b) a=min((int)(a),(int)(b))
#define chkmax(a,b) a=max(a,b)
using namespace std;
const int INF=4*1e18;

int power2(int exp){
    return 1ll<<exp;
}

int lastOne=-1;

int findLastZero(int n){
    int p=-1,cnt=0;
    for(int i=0;n>0;n=n>>1,i++){
            //cout<<n<<endl;
        if(n%2==0) {
            p=i;
            cnt++;
        }
    }
    if (cnt > 1) return p;
    lastOne=p;
    return -1;
}



int32_t main(){
    int x;cin>>x;
    int t=0;
    vi n;
    int pos;
    while((pos=findLastZero(x))!=-1 ){
        t+=2;
        n.pb(pos+1);
        x=(x^(power2(pos+1)-1));
        if (findLastZero(x)==-1 && lastOne==-1) {
            t--;
            break;
        }
        x++;
    }
    if (lastOne!=-1){
        if (lastOne==0){
            t+=2;
            n.pb(0);
        }
        else{
            t+=3;
            n.pb(0);
            n.pb(lastOne);
        }
    }
    cout<<t<<endl;
    loop(i,0,n.size()) cout<<n[i]<<" ";
    return 0;
}