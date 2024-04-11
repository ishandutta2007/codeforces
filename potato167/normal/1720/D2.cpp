#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
ll mod=998244353;
#define rep(i,a) for (int i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}



namespace po167{
template<int char_size,int base>
struct Trie_Tree
{
	struct Node{
		std::vector<int> next_node;
		Node(int c_):next_node(char_size){
			for(int i=0;i<char_size;i++) next_node[i]=-1;
		}
	};
	std::vector<Node> nodes;
	Trie_Tree(){
		nodes.push_back(Node(-1));
	}
	vector<int> insert(std::string &word,int word_id){
		int node_id=0;
		vector<int> ids={0};
		for(int i=0;i<(int)word.size();i++){
			node_id=min_insert(word[i],node_id,word_id);
			ids.push_back(node_id);
		}
		return ids;
	}
	int min_insert(char ch,int node_id,int word_id){
		int c=(int)(ch-base);
		int next_id=nodes[node_id].next_node[c];
		if(next_id==-1){
			next_id=(int)nodes.size();
			nodes.push_back(Node(c));
		}
		nodes[node_id].next_node[c]=next_id;
		node_id=next_id;
		return node_id;
	}
};
}
using po167::Trie_Tree;



void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int N;
	cin>>N;
	Trie_Tree<2,'0'> T;
	vector<vector<int>> dp(2,vector<int>(N*30+10));
	auto f=[](int a)->string{
		string S;
		rep(i,30){
			S+=('0'+a%2);
			a/=2;
		}
		reverse(all(S));
		return S;
	};
	int ans=0;
	rep(i,N){
		int a;
		cin>>a;
		a^=i;
		string S=f(a);
		auto ids=T.insert(S,i);
		int v=1;
		rep(j,30){
			int c=S[j]-'0';
			int tmp=T.nodes[ids[j]].next_node[c^1];
			if(tmp!=-1){
				int b=(c^((i>>(29-j))&1)^1);
				chmax(v,dp[b][tmp]+1);
			}
		}
		chmax(ans,v);
		rep(j,30){
			chmax(dp[(i>>(29-j))&1][ids[j+1]],v);
		}
	}
	cout<<ans<<"\n";
}