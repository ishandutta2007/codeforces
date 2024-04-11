#include <iostream>

using namespace std;

const int MAXV=100111;

int V=100000;
int Cnt[MAXV];

int T;
int P[3];
int Num[8], Vis[8];
int Dfn[1<<14], DFN;

int gcd(int a, int b){
	return (b==0)?a:gcd(b, a%b);
}

long long Ans;

long long C(int n, int k){
	//cout << n << " " << k << "=";
	long long ret=1LL;
	for(int i=0;i<k;++i)
		ret*=(long long)(n-i);
	for(int i=1;i<=k;++i)
		ret/=(long long)(i);
	//cout << ret << " ";
	return ret;
}

void Calc(){
	int k=0;
	for(int i=1;i<=7;++i)	k=(k<<2)+Vis[i];
	if(Dfn[k]==DFN)	return;
	Dfn[k]=DFN;
	long long ret=1LL;
	for(int i=1;i<=7;++i){
		if(Vis[i]>0){
			//ret*=C(Vis[i]+Num[i]-1, Num[i]-1);
			ret*=C(Vis[i]+Num[i]-1, Vis[i]);
		}
		//cout << Vis[i];
	}
	//cout << "=" << ret << endl;
	Ans+=ret;
}

void DFS(int a){
	if(a>=3){
		Calc();
		return;
	}
	for(int i=1;i<=7;++i){
		if(((i&(1<<a))!=0) && Num[i]>0){
			++Vis[i];
			DFS(a+1);
			--Vis[i];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	for(int i=1;i<=V;++i){
		for(int j=1;j<=i/j;++j){
			if(i%j==0){
				++Cnt[i];
				if(j!=(i/j))	++Cnt[i];
			}
		}
	}
	
	cin >> T;
	
	while(T--){
		cin >> P[0] >> P[1] >> P[2];
		//cout << "!" << endl;
		for(int i=1, g=0;i<=7;++i){
			g=0;/**/
			for(int k=0;k<3;++k){
				if((i&(1<<k))!=0)
					g=gcd(P[k], g);
			}
			Num[i]=Cnt[g];
		}
		//for(int i=1;i<=7;++i)	cout << Num[i] << " ";
		//cout << endl;
		//cout << "!" << endl;
		for(int i=7;i>2;--i){
			for(int j=i-1;j>=1;--j){
				if((i&j)==j)
					Num[j]-=Num[i];
			}
		}
		//for(int i=1;i<=7;++i)	cout << Num[i] << " ";
		//cout << endl;
		//cout << "!" << endl;
		Ans=0LL;
		++DFN;
		DFS(0);
		cout << Ans << endl;
	}
	
	return 0;
}

/*
4
14005 66999 1256
3028 13458 62324
78842 69078 58718
6017 99328 28145

256
255
1010
704

*/