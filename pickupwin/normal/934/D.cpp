#include <iostream>

using namespace std;

const int MAXN=11111111;

long long p, k, t, r;
long long ANS[MAXN], L=0;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> p >> k;
	
	while(p<0 || p>=k){
		t=p/(-k);
		r=p+t*k;
		if(t>=0 && r!=0)	++t;
		r=p+t*k;
		//cout << r << " ";
		ANS[++L]=r;
		p=t;
	}
	ANS[++L]=p;
	cout << L << endl;
	for(int i=1;i<=L;++i)
		cout << ANS[i] << " ";
	cout << endl;
	
	return 0;
}