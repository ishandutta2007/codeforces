#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define MAX 100010
#define double long double
lli inf = pow(10,9)+10;
lli modulo = pow(10,9)+7;
double eps = 1e-11;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
bool inb(int a, int b, int c){
	return a>=min(b,c) && a<=max(b,c);
}
struct Point{
	int x,y;
	Point(){	}
	Point(int x,int y) : x(x) , y(y) {	}
};


int getArea(vector<pair<int,int> > a){
	int s = 0;
	fori((int)a.size()){
		int nx = (i+1)%a.size();
		s+=(a[i].ff*a[nx].ss - a[i].ss*a[nx].ff);
	}
	return fabs(s);
}
int fr(set<int>& a){
	return *a.begin();
}
int ls(set<int>& a){
	set<int> :: iterator it = a.end(); --it; return *it;
}
void deal(){
	int a[4][2];
	int b[4][2];
	fori(4)
		forj(2)
			cin>>a[i][j];
	fori(4)
		forj(2)
			cin>>b[i][j];
	fori(4)
		forj(4){
			int nx = (i+1)%4;
			int nx1 = (j+1)%4;
			if(a[i][0] == a[nx][0]){
				int k  = (b[nx1][1] - b[j][1]) / (b[nx1][0] - b[j][0]);
				int bo  = b[j][1] - k*b[j][0];
				int y = k*a[i][0] + bo;
				if( inb(a[i][0], b[j][0] , b[nx1][0]) && inb(y,b[j][1],b[nx1][1]) && inb(y,a[i][1],a[nx][1])){
					cout<<"YES";
					return;
				} 
			}
			else if(a[i][1] == a[nx][1]){
				int k  = (b[nx1][0] - b[j][0]) / (b[nx1][1] - b[j][1]);
				int bo  = b[j][0] - k*b[j][1];
				int x  = k*a[i][1] + bo;
				if( inb(x, b[j][0] , b[nx1][0]) && inb(a[i][1],b[j][1],b[nx1][1]) && inb(x,a[i][0],a[nx][0])){
					cout<<"YES";
					return;
				}
			}
		}
	set<int> to[2][2]; // 0 - which square, 1 - which axis
	fori(4){
		to[0][0].insert(a[i][0]);
		to[0][1].insert(a[i][1]);
		to[1][0].insert(b[i][0]);
		to[1][1].insert(b[i][1]);
	}
	vector<pair<int,int> > fa;
	fori(4)	fa.push_back(mp(b[i][0],b[i][1]));
	int esl = getArea(fa);
	fori(4){
		if(inb(b[i][0],fr(to[0][0]),ls(to[0][0])) && inb(b[i][1],fr(to[0][1]),ls(to[0][1]))){
			cout<<"YES";
			return;
		}
		vector<pair<int,int> > th;
		int s = 0;
		forj(4){
			int nx = (j+1)%4;
			vector<pair<int,int> > th;
			th.push_back(mp(b[j][0],b[j][1]));th.push_back(mp(b[nx][0],b[nx][1]));th.push_back(mp(a[i][0],a[i][1]));
			s+=getArea(th);
		}
		if(s==esl){
			cout<<"YES";
			return;
		}
	}
	cout<<"NO";
}
int main() {
//	while(1)
	deal();
}