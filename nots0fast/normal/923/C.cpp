#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(4)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define MAX 100010
#define double long double
#define ch 400
int inf = pow(10,9);
lli modulo = pow(10,9)+7;
lli md = pow(10,9)+7;
double eps = 1e-13;
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
void Insert(Node* Root , int eded, int necenci)
{
	while(necenci>-1){
		if(eded & (1<<necenci))
		{
	//		cout<<"rrrrrrrr \n";
			Root->rightsay++;
			if(Root->right == NULL)
				Root->right = new Node();
			Root = Root->right;
		}
		else{
	//		cout<<"llllllll \n";
			Root->leftsay++;
			if(Root->left == NULL)
				Root->left = new Node();
			Root = Root->left;
		}
		--necenci;
	}
}
void checker(Node* root, int eded, int nece, int& cons){
	while(nece>-1){
	//	cout<<"we are at level "<<nece<<" the leftsay: "<<root->leftsay<<" the rightsay: "<<root->rightsay<<endl;
		if((1<<nece)&eded){
			if(root->rightsay>0){
				root->rightsay--;
				root = root->right;
			}
			else{
				root->leftsay--;
				cons^=(1<<nece);
				root = root->left;
			}
		}
		else{
			if(root->leftsay>0){
				root->leftsay--;
				root = root->left;
			}
			else{
				root->rightsay--;
				cons^=(1<<nece);
				root = root->right;
			}
		}
		--nece;
	}
}
void deal(){
	Node* Root = new Node();
	int n;
	cin>>n;
	int arr[n];
	fori(n)
		cin>>arr[i];
	fori(n){
		int ed;
		cin>>ed;
		Insert(Root,ed,31);
	}
	fori(n){
		int num = 0;
		checker(Root,arr[i],31,num);
		cout<<num<<' ';
	}
}
int main() {
	deal();
}