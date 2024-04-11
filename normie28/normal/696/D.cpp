
// Problem : D. Legen...
// Contest : Codeforces - Codeforces Round #362 (Div. 1)
// URL : https://codeforces.com/contest/696/problem/D
// Memory Limit : 256 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
#define alpha_size 26 // Size of the alphabet.
#define shift_const -97 // Add to the value of the character this much when converting the character into an int.



struct node // Structure representing a node.
{
	int parent,slink,trans[alpha_size];
	/*
	parent: id of node's parent. 0 if this node is the root.
	slink: id of node's direct suffix link. 1 if this node is the root.
	trans[i]: The next node's id if the next character in the automaton is i. Will be found recursively using slink
	negative: use suffix link
	positive: use trie link
	0: not set
	-1 if this node is the root and there's no trie link with this character.
	*/
	int pedge;
	/*
	pedge: character of the edge connecting parent of node to node. (-1 if the node is the root)
	*/
	vector<int> leaf;
	int sval=0;
	/*
	leaf: list of ids of strings that are suffixes of the string represented by current node. Will be found recursively using slink
	*/
	int next_match;
	/*
	next_match: The nearest node reachable by suflinks that has leaf.size()>0.
	*/
	 node(int par=0 ,int edge=0) // Constructor
	{
		for (int i=0;i<alpha_size;i++) trans[i]=0; 
		parent=par;
		slink=0;
		pedge=edge;
		leaf={};
	}	
};



struct aho_cora // Structure representing a suffix automaton.
{
	public:
		vector<node> trie; // A vector of nodes representing the trie.
		int scnt=0; // Count of strings added to the trie. Will be used to number the strings added to the trie.
		deque<int> dq; // Used in add_suflink() as a queue for the nodes to be processed (by id).
		int add_node (int par, int last) 
		/*
		Add a node into the tree with parent par and edge character last.
		*/
		{
			trie.push_back(node(par,last));
			int cur=trie.size()-1;
			
			return cur;
		}
		void add_suflink_node(int cur)
		/*
		Add the suffix links and transition table for node cur.
		Also calculates next_match.
		*/
		{
			if (trie[cur].parent<=1) trie[cur].slink=1; // If string represented by node has <=1 character, then it has no suffixes, so its direct suffix link is 1. 
			else  
			trie[cur].slink=abs(trie[trie[trie[cur].parent].slink].trans[trie[cur].pedge]); 
			/*
			"to find a suffix link for some vertex v, then we can go to the ancestor 
			p of the current vertex (let c be the letter of the edge from p to v), 
			then follow its suffix link, and perform from there the transition with the letter c."
			*/
			for (int i=0;i<alpha_size;i++) if (trie[cur].trans[i]<=0) trie[cur].trans[i]=-abs(trie[trie[cur].slink].trans[i]);
			/*
			For transitions not using trie links, import the transition results from the node's suffix link node.
			*/
			for (int i=0;i<alpha_size;i++) if (trie[cur].trans[i]>0) dq.push_back(trie[cur].trans[i]);
			/*
			Adds the node's children (in trie) to the queue.
			*/
			if (cur==1)
			{
			    trie[cur].next_match=0;
			}
			else
			if (trie[trie[cur].slink].leaf.size())
			{
			    trie[cur].next_match=trie[cur].slink;
			}
			else
			{
			    trie[cur].next_match=trie[trie[cur].slink].next_match;
			}
			trie[cur].sval+=trie[trie[cur].slink].sval;
			/*
			Calculates next_match.
			*/
		}
	public:
		 aho_cora() // Constructor
		{
			trie.push_back(node(0));
			trie.push_back(node(0));
			trie[1].parent=0;
			trie[1].slink=1;
			trie[1].pedge=-1;
			trie[1].leaf={};
			trie[1].next_match=0;
			for (int i=0;i<alpha_size;i++) trie[1].trans[i]=-1;
		}
		void add_string (string s, int v) //Adds a string to the trie.
		{
			scnt++; //Increments the string counter. This string's id is now scnt.
			int cur=1,n=s.length(); //Starts at node 1
			for (int i=0;i<n;i++)
			{
				if (trie[cur].trans[s[i]+shift_const]<=0) //If there's no trie link with this character yet, create a new one (along with a new node)
				{	
				int ass=add_node(cur,s[i]+shift_const);
				trie[cur].trans[s[i]+shift_const]=ass;
				}
				cur=trie[cur].trans[s[i]+shift_const]; //Transitions to next node via the trie link for the current character.
				
		//		cout<<s<<' '<<v<<' '<<cur<<endl;
			}
			trie[cur].leaf.push_back(scnt); //Once we've arrived at the node for the string, add the string id to its leaf vector.
			trie[cur].sval+=v;
		}
		void check_graph() // Some debug stuff, no need to pay attention
		{
			for (int i=1;i<trie.size();i++)
			{
			cout<<i<<' '<<trie[i].parent<<' '<<trie[i].slink<<' '<<trie[i].sval<<endl;
			for (int j=0;j<alpha_size;j++) cout<<trie[i].trans[j]<<' ';
			cout<<endl;
			for (int g: trie[i].leaf) cout<<g<<' ';
			cout<<endl;
			}
		}
		void add_suflink() 
		/*
		Add the suffix links and transition table for every node in the trie.
		The function uses BFS to ensure that the neccessary nodes are processed before a given node is processed.
		*/
		{
			dq.push_back(1); // Processes root first
			while (dq.size())
			{
				add_suflink_node(dq.front()); // Processes the node at top of queue; see add_suflink_node()
				dq.pop_front(); // then removes it from queue
			}
		}
};




vector<vector<ll>> mulmm(vector<vector<ll>> a, vector<vector<ll>> b)
{
	ll n=a.size();
//	cout<<a.size()<<a[0].size()<<b.size()<<b[0].size()<<endl;
	vector<vector<ll>> c=vector<vector<ll>>(n,vector<ll>(n,-4e18));
//	cout<<c.size()<<c[0].size()<<endl;
	for (ll i=0;i<n;i++) for (ll j=0;j<n;j++) for (ll u=0;u<n;u++)
	{
//		cout<<i<<' '<<j<<' '<<u<<endl;
		c[i][j]=max(c[i][j],a[i][u]+b[u][j]);
	}
	return c;
}
vector<ll> mulvm (vector<ll> a, vector<vector<ll>> b)
{
	ll n=a.size();
	vector<ll> c=vector<ll> (n,-4e18);
	for (ll i=0;i<n;i++) for (ll j=0;j<n;j++) 
	{
		c[j]=max(c[j],a[i]+b[i][j]);
	}
	return c;
}
vector<vector<ll>> bowm(vector<vector<ll>> a, ll x)
{
//	cout<<"bowm "<<' '<<x<<endl;
	if (x==1) return a;
	auto res=bowm(a,x/2);
	res=mulmm(res,res);
	if (x%2) res=mulmm(res,a);
	return res;
}




aho_cora ac;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll arr[201];
vector<vector<ll>> trans;
vector<ll> base,res;
string s;
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>arr[i];
	for (i=1;i<=n;i++)
	{
		cin>>s; 
		ac.add_string(s,arr[i]);
	}
	ac.add_suflink();
	//ac.check_graph();
	
	for (i=1;i<ac.trie.size();i++) 
	{
		trans.push_back({});
	for (j=1;j<ac.trie.size();j++)  trans[i-1].push_back(-4e18);
	}
	
	for (i=1;i<ac.trie.size();i++)
	{
		for (j=0;j<26;j++) 
		{
		u=ac.trie[i].trans[j];
		u=abs(u);
	//	cout<<i<<' '<<j<<' '<<u<<endl;
		trans[i-1][u-1]=ac.trie[u].sval;
	//	if (trans[i-1][u-1]) cout<<i<<' '<<u<<' '<<trans[i-1][u-1]<<endl;
		}
	}
	
	for (i=1;i<ac.trie.size();i++) if (i==1) base.push_back(0); else base.push_back(-4e18);
	res=mulvm(base,bowm(trans,m));
	a=0;
	for (i=0;i<ac.trie.size()-1;i++) a=max(a,res[i]);
	cout<<a;
	
}