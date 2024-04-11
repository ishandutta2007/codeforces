#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(1)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define lli long long int
#define double long double
#define MAX 100101
int inf = pow(10,9);
double eps = pow(10,-18);
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main(){
	int fen[4][10][MAX] = { };
	string s;
	string nuk = "ATCG";
	cin>>s;
	fori(s.length()){
		int xan = nuk.find(s[i]);
		forj(10){
			int index = i+1;
			while(index<MAX){
				fen[xan][j][index]++;
				int eded = index/(j+1)+1;
				index += (eded&-eded)*(j+1);
			}
		}
	}
	int q;
	cin>>q;
	fori(q){
		int c;
		cin>>c;
		if(c==1){
			int x;
			char f;
			cin>>x>>f;
			--x;
			int xan = nuk.find(s[x]);
			forj(10){
				int index = x+1;
				while(index<MAX){
					fen[xan][j][index]--;
					int eded = index/(j+1)+1;
					index += (eded&-eded)*(j+1);
				}
			}
			s[x] = f;
			xan = nuk.find(s[x]);
			forj(10){
				int index = x+1;
				while(index<MAX){
					fen[xan][j][index]++;
					int eded = index/(j+1)+1;
					index += (eded&-eded)*(j+1);
				}
			}
		}
		else{
			int l,r;
			string e;
			cin>>l>>r>>e;
			int len = e.length();
			int say = 0;
			fori(e.length()){
				int xan = nuk.find(e[i]);
				int index = l+i;
				int bes = index%len;
				int index1 = index - len ;
				int index2 = r;
				while(index2>0 && index2%len!=bes)
					--index2;
				int sum1 = 0, sum2 = 0;
				while(index1>0){
					sum1+=fen[xan][len-1][index1];
					int eded = index1/len+1;
					index1 -= (eded&-eded)*len;
				}
				while(index2>0){
					sum2+=fen[xan][len-1][index2];
					int eded = index2/len+1;
					index2 -= (eded&-eded)*len;
				}
	//			cout<<xan<<" "<<sum2<<" "<<sum1<<" "<<endl;
				say+=sum2-sum1;
			}
			cout<<say<<'\n';
		}
	}
}