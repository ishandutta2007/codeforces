#include <iostream>

using namespace std;

const int MAXM=111111;

int A, B, M, R0;

int Pos[MAXM];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> A >> B >> M >> R0;
	
	for(int i=1, j=R0;i<=M+1;++i){
		if(Pos[j]!=0){
			cout << i-Pos[j] << endl;
			break;
		}
		Pos[j]=i;
		j=(int)(((long long)(A)*(long long)(j)+(long long)(B))%(long long)(M));
	}
	
	return 0;
}