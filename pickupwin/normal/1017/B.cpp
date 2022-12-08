#include <iostream>
#include <string>

using namespace std;

const int MAXN=100111;

string input;
int N;
int A[MAXN], B[MAXN];
int CntA1, CntA0, CntA1B0, CntA0B0;

long long Ans;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	cin >> input;
	for(int i=1;i<=N;++i)
		A[i]=input[i-1]-'0';
	cin >> input;
	for(int i=1;i<=N;++i)
		B[i]=input[i-1]-'0';
	
	for(int i=1;i<=N;++i){
		if(A[i]==1){
			++CntA1;
			if(B[i]==0)
				++CntA1B0;
		}
		if(A[i]==0){
			++CntA0;
			if(B[i]==0)
				++CntA0B0;
		}
	}
	
	Ans=0LL;
	Ans+=(long long)(CntA1B0)*(long long)(CntA0);
	Ans+=(long long)(CntA0B0)*(long long)(CntA1);
	Ans-=(long long)(CntA0B0)*(long long)(CntA1B0);
	
	cout << Ans << endl;
	
	return 0;
}