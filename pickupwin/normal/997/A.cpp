#include <iostream>
#include <string>

using namespace std;

const int MAXN=300111;

int N;
long long A, B;
int Num[MAXN];
string input;
int Cnt=0; 

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	cin >> A >> B;
	
	cin >> input;
	for(int i=1;i<=N;++i)
		Num[i]=input[i-1]-'0';
	
	Num[++N]=1;
	for(int i=1, h=Num[1];i<=N;++i){
		if(Num[i]!=h){
			h=Num[i];
			if(h==1)	++Cnt;
		}
	}
	//cout << Cnt << endl;
	
	long long Ans;
	if(Cnt==0)	Ans=0LL;
	else if(A<=B)	Ans=A*(Cnt-1)+B;
	else	Ans=B*Cnt;
	cout << Ans << endl;
	
	return 0;
}