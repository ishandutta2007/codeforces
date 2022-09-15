#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll mod=1e9+7;
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

void solve();

//tourist toast
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	rep(i,T) solve();
}

void solve(){
	int n;
	string S;
	cin>>S;
	n=S.size();
	vector<int> p(26,0);
	int ind=100;
	rep(i,n) p[(int)(S[i]-'a')]++;
	rep(i,26){
		if(p[i]==0) continue;
		chmin(ind,i);
		if(p[i]==1){
			int k;
			rep(j,n){
				if(S[j]==(char)('a'+i)) k=j;
			}
			S[k]=(char)('a');
			sort(S.begin(),S.end());
			S[0]=(char)('a'+i);
			cout<<S<<"\n";
			return ;
		}
	}
	if(p[ind]<=n/2+1){
		char minmum=(ind+'a');
		string T="";
		T+=minmum;
		T+=minmum;
		int s=p[ind];
		sort(S.begin(),S.end());
		p[ind]-=2;
		for(int i=s;i<n;i++){
			T+=S[i];
			if(p[ind]!=0){
				p[ind]--;
				T+=minmum;
			}
		}
		cout<<T<<"\n";
		return ;
	}
	if(p[ind]!=n){
		sort(S.begin(),S.end());
		swap(S[1],S[p[ind]]);
		if(p[ind]!=n-1&&S[p[ind]+1]==S[1]){
			int k=p[ind]+1;
			while(k<n&&S[k]==S[1]) k++;
			if(k!=n){
				swap(S[k],S[p[ind]+1]);
			}
			else{
				sort(S.begin(),S.end());
				reverse(S.begin(),S.end());
				for(int i=n-1;i>0;i--) swap(S[i],S[i-1]);
			}
		}
	}
	cout<<S<<"\n";
	return ;
}