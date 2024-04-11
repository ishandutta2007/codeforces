#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

//a:Nlog(log(N))
vector<long long> Eratosthenes(long long a){
    if(a<2) return {};
    vector<long long> p(a+1),ans;
    p[0]=1,p[1]=1;
    long long k=2;
    while(k*k<=a){
        if(p[k]==0){
            ans.push_back(k);
            for(long long i=2;i*k<=a;i++){
                p[i*k]=1;
            }
        }
        k++;
    }
    while(k<=a){
        if(p[k]==0) ans.push_back(k);
        k++;
    }
    return ans;
}
vector<ll> table=Eratosthenes(1000);
void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
    cin>>n;
    int front=-1,tmp;
    int x,y;
    vector<int> ans(1+n);
    rep(i,n-2){
        cout<<"? "<<i+1<<" "<<i+2<<" "<<i+3<<endl;
        cin>>tmp;
        if(front+tmp==1){
            x=i,y=i+3;
            if(tmp==0) ans[y]=1;
            else ans[x]=1;
            break;
        }
        front=tmp;
    }
    int num=1;
    rep(i,n+1){
        if(i==x||i==y||i==0) continue;
        cout<<"? "<<x<<" "<<y<<" "<<i<<endl;
        cin>>tmp;
        ans[i]=1-tmp;
        num+=1-tmp;
    }
    cout<<"! "<<num;
    rep(i,n+1){
        if(ans[i]) cout<<" "<<i;
    }
    cout<<endl;
}