#include <iostream>

using namespace std;

const int MAXN=111111;

int N, K;
int Num[MAXN];
int SG[MAXN];
int ToSG[5]={0, 1, 0, 1, 2};

int calc(int k){
	if(k<=4)	return ToSG[k];
	if(k&1)	return 0;
	bool Used[3]={false, false, false};
	Used[calc(k-1)]=true;
	Used[calc(k>>1)]=true;
	for(int i=0;i<3;++i)	if(!Used[i])	return i;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> K;
	
	for(int i=1;i<=N;++i)	cin >> Num[i];
	
	if(K%2==0){
		for(int i=1;i<=N;++i){
			if(Num[i]==1){
				SG[i]=1;continue;
			}
			if(Num[i]==2){
				SG[i]=2;continue;
			}
			SG[i]=(!(Num[i]&1));
		}
	}
	else{
		for(int i=1;i<=N;++i){
			if(Num[i]<=4)	SG[i]=ToSG[Num[i]];
			else if(Num[i]&1)	SG[i]=0;
			else	SG[i]=calc(Num[i]);
		}
	}
	
	int ANS=0;
	for(int i=1;i<=N;++i)
		ANS^=SG[i];
	
	if(ANS!=0)	cout << "Kevin" << endl;
	else	cout << "Nicky" << endl;
	
	return 0;
}