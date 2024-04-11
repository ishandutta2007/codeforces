#include <iostream>

using namespace std;

const int MAXN=100111;

int N;
int Ans;
int Out[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	Ans=N+1;
	for(int i=1, j;i<=N;++i){
		j=N/i;
		if(N%i!=0)	++j;
		Ans=min(Ans, i+j);
	}
	
	//cout << Ans << endl;
	
	for(int i=1, j;i<=N;++i){
		j=N/i;
		if(N%i!=0)	++j;
		if(i+j==Ans){
			//cout << i << " " << j << endl;
			for(int jj=1, s=N;jj<=j;++jj){
				for(int ii=min(i, s), p;ii>=1 && s>0;--ii){
					p=(jj-1)*i+ii;
					Out[p]=s--;
				}
			}
			break;
		}
	}
	
	for(int i=1;i<=N;++i)
		cout << Out[i] << " ";
	cout << endl;
	
	return 0;
}