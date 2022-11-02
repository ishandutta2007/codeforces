#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n,m;
int d[82][1<<18];
int r[82][1<<18];
int f[82][1<<18];
int TEMP[]={
	0,
	0,
	0,
	0};

void buildTEMP(){
	TEMP[0] = (1<<2)|(1<<n)|(1<<(n+1))|(1<<(n+2))|(1<<(2*n+2));
	TEMP[1] = (1<<0)|(1<<1)|(1<<2)|(1<<(n+1))|(1<<(2*n+1));
	TEMP[2] = (1<<0)|(1<<n)|(1<<(2*n))|(1<<(n+1))|(1<<(n+2));
	TEMP[3] = (1<<1)|(1<<(n+1))|(1<<(2*n+1))|(1<<(2*n))|(1<<(2*n+2));
}

char rr[20][20];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	if(n<3 || m<3){
		puts("0");
		REP(i,n){
			REP(j,m)printf(".");
			puts("");
		}
	}else if(n==9 && m==9){
		cout<<"13"<<endl;
		cout<<"M..GGG..C"<<endl;
		cout<<"MMMJGECCC"<<endl;
		cout<<"MJJJGEEEC"<<endl;
		cout<<"LLLJHE..B"<<endl;
		cout<<".LHHHDBBB"<<endl;
		cout<<".L.IHDDDB"<<endl;
		cout<<"KIIIFDAAA"<<endl;
		cout<<"KKKIF..A."<<endl;
		cout<<"K..FFF.A."<<endl;
	}else{
		bool sw = false;
		if(n==9){
			swap(n,m);
			sw=true;
		}
		buildTEMP();
		CL(r,-1);CL(d,-1);CL(f,-1);
		r[0][0]=0;
		int nmask = 2*n+2;
		int max_mask = 1<<nmask; max_mask--;
		REP(pos,m*n)REP(mask,1<<nmask)if(r[pos][mask]!=-1){
			int row = pos%n;
			int col = pos/n;
			if( r[pos+1][(mask<<1)&max_mask] == -1 || r[pos+1][(mask<<1)&max_mask] < r[pos][mask]){
				r[pos+1][(mask<<1)&max_mask] = r[pos][mask];
				d[pos+1][(mask<<1)&max_mask] = -1;
				f[pos+1][(mask<<1)&max_mask] = mask;
			}
			if(row>=1 && col>=2 && row!=n-1){
				int tmask = mask<<1;
				REP(tmp,4){
					if(!(tmask&TEMP[tmp])){
						int nmask = ((tmask|TEMP[tmp]))&max_mask;
						if( r[pos+1][nmask] < r[pos][mask]+1){
							r[pos+1][nmask] = r[pos][mask]+1;
							d[pos+1][nmask] = tmp;
							f[pos+1][nmask] = mask;
						}
					}
				}
			}
		}
		int mx = 0;
		int cel = n*m-1;
		REP(j,1<<nmask)if(r[cel][j] > r[cel][mx]) mx = j;
		cout<<r[cel][mx]<<endl;
		REP(i,n)REP(j,m) rr[i][j]='.';

		int num=0;
		while(cel){

			//cout<<cel<<' '<<r[cel][mx]<<' '<<mx<<' '<<TEMP[2]<<' '<<d[cel][mx]<<endl;
			if(d[cel][mx]!=-1){
				int row = (cel)%n;
				int col = (cel)/n;
				int tt = d[cel][mx];
				REP(i,nmask+1)if(TEMP[tt]&(1<<i)){
					int dx=0,dy=0;
					if(i<n) dx=i;
					else if(i<2*n) dx=i-n,dy=1;
					else dx=i-2*n,dy=2;
					rr[row-dx][col-dy] = char('A'+num);
				}
				//cout<<row<<' '<<col<<' '<<tt<<' '<<cel<<endl;
				//puts("FUICK");
				num++;
			}
			mx = f[cel][mx];
			cel--;
		}
		if(sw) swap(n,m);
		REP(i,n){
			REP(j,m){
				if(sw)printf("%c",rr[j][i]);
				else printf("%c",rr[i][j]);
			}
			puts("");
		}
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}