
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
#define shift_const -97 // Add to the value of the character this much when converting the character llo an ll.
typedef int int_t; 
 
struct seg
{
    int_t val[4000044]; //Contains the current value of each node, as weint as the lazy propagation amount stored.
    int_t tree_n;
    void resetK (int_t node, int_t l, int_t r) // Resets the tree nodes. 
    {
        if (l==r)
        {
            val[node]=0;
        }
        else
        {
            int_t mid=(l+r)/2;
            resetK(node<<1,l,mid);
            resetK((node<<1)+1,mid+1,r);
            val[node]=val[node<<1]+val[(node<<1)+1];
        }
    }
    void reset(int_t n)
    {
        resetK(1,1,n);
        tree_n=n;
    }
    void updateK(int_t node, int_t l, int_t r, int_t tar_l, int_t tar_r, int_t diff)
    {
   //     cout<<"updateK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar_r)or(r<tar_l)) return;
        else if ((l>=tar_l)and(r<=tar_r))
        {
            val[node]+=diff;
        }
        else
        {
            int_t mid=(l+r)/2;
            updateK(node<<1,l,mid,tar_l,tar_r,diff);
            updateK((node<<1)+1,mid+1,r,tar_l,tar_r,diff);
        }
        
    }
    void update(int_t l, int_t r, int_t diff)
    {
        updateK(1,1,tree_n,l,r,diff);
    }
    int_t getK(int_t node, int_t l, int_t r, int_t tar)
    {
 
  //      cout<<"getK "<<node<<' '<<l<<' '<<r<<' '<<tar_l<<' '<<tar_r<<endl; 
        if ((l>tar)or(r<tar)) return 0;
        else 
        {
        	int_t res=val[node];
            int_t mid=(l+r)/2;
            int_t aa=0; if (l<r) aa=getK(node<<1,l,mid,tar);
            int_t bb=0; if (l<r) bb=getK((node<<1)+1,mid+1,r,tar);
            return res+aa+bb;
        }
        
    }
    int_t get(int_t l)
    {
        return getK(1,1,tree_n,l);
    }
};
 
struct node // Structure representing a node.
{
	int parent,slink,trans[alpha_size];
	/*
	parent: id of node's parent. 0 if this node is the root.
	slink: id of node's direct suffix link. 1 if this node is the root.
	trans[i]: The next node's id if the next character in the automaton is i. Wiint be found recursively using slink
	negative: use suffix link
	positive: use trie link
	0: not set
	-1 if this node is the root and there's no trie link with this character.
	*/
	int pedge;
	/*
	pedge: character of the edge connecting parent of node to node. (-1 if the node is the root)
	*/
	int leafcnt;
	/*
	leaf: list of ids of strings that are suffixes of the string represented by current node. Wiint be found recursively using slink
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
		leafcnt=0;
	}	
};
 
 
 
struct aho_cora // Structure representing a suffix automaton.
{
		vector<node> trie; // A vector of nodes representing the trie.
		int tl[1000011],tr[1000011];
		seg st;
		int xx;
		vector<int> gt[1000011];
		int scnt=0; // Count of strings added to the trie. Wiint be used to number the strings added to the trie.
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
			then fointow its suffix link, and perform from there the transition with the letter c."
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
			if (trie[trie[cur].slink].leafcnt)
			{
			    trie[cur].next_match=trie[cur].slink;
			}
			else
			{
			    trie[cur].next_match=trie[trie[cur].slink].next_match;
			}
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
			trie[1].leafcnt=0;
			trie[1].next_match=0;
			for (int i=0;i<alpha_size;i++) trie[1].trans[i]=-1;
		}
		int add_string (string s) //Adds a string to the trie.
		{
	//		cout<<"add_string "<<s<<endl;
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
			}
			trie[cur].leafcnt=1;
			return cur;
		}
		ll check_string(string s) 
		/*
			Returns aint occurences of pattern strings in the given text, in the form of a vector of pairs. 
			First element is the end position of the matching pattern string (relative to the text).
			Second element is the id of the matching patten string 
			(pattern strings are numbered from 1 to n, based on when you added them) 
		*/
		{
	//		cout<<"check_string "<<s<<endl;
			ll res=0;
			int n=s.length();
			int cur=1; // Starts at node 1
			for (int i=0;i<n;i++)
			{
				cur=abs(trie[cur].trans[s[i]+shift_const]); // Transitions to next node based on the current character.
				res+=st.get(tl[cur]);
			}
			return res;
		}
		void check_graph() // Some debug stuff, no need to pay attention
		{
			for (int i=1;i<trie.size();i++)
			{
			cout<<i<<' '<<trie[i].parent<<' '<<trie[i].slink<<' '<<endl;
			for (int j=0;j<alpha_size;j++) cout<<trie[i].trans[j]<<' ';
			cout<<endl;
			cout<<trie[i].leafcnt;
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
		void dfs(int x)
		{
			xx++;
			tl[x]=xx;
			for (int g : gt[x]) dfs(g);
			tr[x]=xx;
		}
		void prepare()
		{
			xx=0;
			for (int i=2;i<trie.size();i++) gt[trie[i].slink].push_back(i);
			dfs(1);
			st.reset(trie.size()-1);
			for (int i=1;i<trie.size();i++) st.update(tl[i],tr[i],trie[i].leafcnt);
		}
		void aho_add(int i)
		{
			st.update(tl[i],tr[i],1);
		}
		void aho_sub(int i)
		{
			st.update(tl[i],tr[i],-1);
		}
};
aho_cora gr;
int ind[100001],stat[100001];
string s;
int n,m,i,j,k,t,t1,u,v,a,b;
void add()
{
	s.erase(s.begin());
//	cout<<"add "<<s<<endl;
	int i=stoi(s);
	if (!stat[i])
	{
		stat[i]=1;
		gr.aho_add(ind[i]);
	}
}
void sub()
{
	s.erase(s.begin());
//	cout<<"sub "<<s<<endl;
	int i=stoi(s);
	if (stat[i])
	{
		stat[i]=0;
		gr.aho_sub(ind[i]);
	}
}
void query()
{
	s.erase(s.begin());
//	cout<<"query "<<s<<endl;
	cout<<gr.check_string(s)<<endl;
}
int main()
{
	fio;
	cin>>m>>n;
	for (i=1;i<=n;i++)
	{
		cin>>s;
		ind[i]=gr.add_string(s);
		stat[i]=1;
	}
	gr.add_suflink();
	gr.prepare();
//	for (i=1;i<=n;i++) gr.trie[ind[i]].leafcnt--;
	for (i=1;i<=m;i++)
	{
		cin>>s;
		if (s[0]=='+') add();
		if (s[0]=='-') sub();
		if (s[0]=='?') query();
	}
}