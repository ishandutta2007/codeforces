#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define double long double
#define MAX 200001
#define cut 701
//#define M_PI 2*acos(0)
lli inf = pow(10,18);
int modulo = inf+7;
double eps = 1e-16;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
struct  Node
{
    Node* left ;
	Node* right ;
	int leftsay = 0;
	int rightsay = 0;	
};
int a;
void Insert(Node* &Root , int eded, int necenci)
{
	if(Root==NULL)
		Root = new Node ();
	if(necenci<0)
		return ;
	else
	{
		if(eded & (1<<necenci))
		{
			Root->rightsay++;
	//		cout<<"rrrrrr\n";
			Insert(Root->right, eded, necenci-1);
		}
		else
		{
			Root->leftsay++;
	//		cout<<"llllll\n";
			Insert(Root->left, eded, necenci-1);
		}
	}
}
int checker (Node *Root, int eded, int necenci, int duz)
{
	if(necenci<0 || Root == NULL)
		return duz;
	int qal = pow(2,necenci);
//	cout<<necenci<<" "<<qal<<" solsay: "<<Root->leftsay<<" sagsay: "<<Root->rightsay<<endl;
	if(eded&(1<<necenci))
	{
		int lz = Root->rightsay;
		if(lz<qal)
			checker(Root->right,eded,necenci-1,duz);
		else{
			duz^=(1<<necenci);
			checker(Root->left,eded,necenci-1,duz);
		}
	}
	else
	{
		int lz = Root->leftsay;
		if(lz<qal)
			checker(Root->left,eded,necenci-1,duz);
		else{
			duz^=(1<<necenci);
			checker(Root->right,eded,necenci-1,duz);
		}
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	Node *root = new Node();
	int n,m;
	cin>>n>>m;
	int res = 0;
	set<int> eds;
	fori(n){
		int ed;
		cin>>ed;
		eds.insert(ed);
	}
	set<int> :: iterator it = eds.begin();
	while(it!=eds.end()){
		Insert(root,*it,20);
		++it;
	}
	fori(m){
		int ed;
		cin>>ed;
		res^=ed;
		cout<<checker(root,res,20,0)<<'\n';
	}
}