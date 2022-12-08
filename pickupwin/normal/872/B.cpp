#include <iostream>
using namespace std;
const int MAXN=111111;
int N, K;
int Num[MAXN];
int max(int a, int b){
	return (a<b)?b:a;
}
int min(int a, int b){
	return (a<b)?a:b;
}
int Worst(){
	int ret=Num[1];
	for(int i=2;i<=N;++i)
		ret=min(ret, Num[i]);
	return ret;
}
int Best(){
	int ret=Num[1];
	for(int i=2;i<=N;++i)
		ret=max(ret, Num[i]);
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for(int i=1;i<=N;++i)
		cin >> Num[i];
	if(K==1)
		cout << Worst();
	else if(K==2)
		cout << max(Num[1], Num[N]);
	else
		cout << Best();
	return 0;
}