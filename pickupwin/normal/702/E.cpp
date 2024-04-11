#include <iostream>

using namespace std;

const int MAXN=100111;
const int INF=1034567890;

int N;
long long K;
int Nxt[MAXN][36];
int Min[MAXN][36];
long long Sum[MAXN][36];

void Ask(int i, long long k){
	long long s=0LL;
	int m=INF;
	for(int d=0;d<36;++d)
		if(((k>>d)&1LL)!=0LL){
			s+=Sum[i][d];
			m=min(m, Min[i][d]);
			i=Nxt[i][d];
		}
	cout << s << " " << m << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> N >> K;
	for(int i=0;i<N;++i)	cin >> Nxt[i][0];
	for(int i=0;i<N;++i)	cin >> Min[i][0];
	for(int i=0;i<N;++i)	Sum[i][0]=Min[i][0];
	
	for(int j=1;j<36;++j)
		for(int i=0;i<N;++i){
			Nxt[i][j]=Nxt[Nxt[i][j-1]][j-1];
			Min[i][j]=min(Min[i][j-1], Min[Nxt[i][j-1]][j-1]);
			Sum[i][j]=Sum[i][j-1]+Sum[Nxt[i][j-1]][j-1];
		}
	
	for(int i=0;i<N;++i)
		Ask(i, K);
	
	return 0;
}