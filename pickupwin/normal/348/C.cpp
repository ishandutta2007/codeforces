#include <iostream>
#include <string>

using namespace std;

const int MAXN=111111;
const int MAXM=111111;

int N, M, Q;
long long Num[MAXN];
int Size;
int Hcnt=0, Lcnt=0;
string Com;
int X, K;
long long ANS=0LL;

int Mem[MAXN], Mcnt=0;

struct Heavy{
	int ML, MR, MC;
	bool Own[MAXN];
	long long Sum, Add;
	int Both[355];
	Heavy(){
		for(int i=0;i<MAXN;++i)
			Own[i]=false;
		for(int i=0;i<355;++i)
			Both[i]=0;
	}
} H[355];

struct Light{
	int ML, MR, MC;
	int Both[355];
	Light(){
		for(int i=0;i<355;++i)
			Both[i]=0;
	}
} L[MAXM];

struct Set{
	bool isH;
	int at;
} S[MAXM];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> Q;
	for(int i=1;i<=N;++i)
		cin >> Num[i];
	
	for(Size=0;Size*Size<N;++Size);
	
	for(int i=1, c;i<=M;++i){
		cin >> c;
		if(c>=Size){
			S[i].isH=true;
			S[i].at=++Hcnt;
			H[Hcnt].MC=c;
			H[Hcnt].ML=Mcnt+1;
			H[Hcnt].MR=H[Hcnt].ML+H[Hcnt].MC-1;
			H[Hcnt].Add=0LL;
			H[Hcnt].Sum=0LL;
			for(int j=1, k;j<=c;++j){
				cin >> k;
				Mem[++Mcnt]=k;
				H[Hcnt].Own[k]=true;
				H[Hcnt].Sum+=Num[k];
			}
		}
		else{
			S[i].isH=false;
			S[i].at=++Lcnt;
			L[Lcnt].MC=c;
			L[Lcnt].ML=Mcnt+1;
			L[Lcnt].MR=L[Lcnt].ML+L[Lcnt].MC-1;
			for(int j=1, k;j<=c;++j){
				cin >> k;
				Mem[++Mcnt]=k;
			}
		}
	}
	
	for(int i=1;i<=Lcnt;++i)
		for(int j=1;j<=Hcnt;++j)
			for(int k=1;k<=L[i].MC;++k)
				if(H[j].Own[Mem[L[i].ML+k-1]])
					++L[i].Both[j];
	
	//cout << L[1].Both[3] << endl;
	
	for(int i=1;i<=Hcnt;++i)
		for(int j=1;j<=Hcnt;++j)
			for(int k=1;k<=H[i].MC;++k)
				if(H[j].Own[Mem[H[i].ML+k-1]])
					++H[i].Both[j];
	
	while(Q--){
		cin >> Com;
		if(Com=="?"){
			cin >> X;
			if(S[X].isH){
				ANS=0LL;
				ANS+=H[S[X].at].Sum;
				//ANS+=H[S[X].at].Add*(long long)(H[S[X].at].Mcnt);
				for(int i=1;i<=Hcnt;++i){
					ANS+=H[i].Add*(long long)(H[S[X].at].Both[i]);
				}
			}
			else{
				ANS=0LL;
				for(int i=1;i<=Hcnt;++i){
					ANS+=H[i].Add*(long long)(L[S[X].at].Both[i]);
					//cout << i << " " << H[i].Add << endl;
				}
				//cout << "1 " << ANS << endl;
				for(int i=1;i<=L[S[X].at].MC;++i)
					ANS+=(long long)(Num[Mem[L[S[X].at].ML+i-1]]);
				//cout << "2 " << ANS << endl;
			}
			cout << ANS << endl;
		}
		else{
			cin >> X >> K;
			if(S[X].isH){
				H[S[X].at].Add+=(long long)(K);
			}
			else{
				for(int i=1;i<=L[S[X].at].MC;++i)
					Num[Mem[L[S[X].at].ML+i-1]]+=(long long)(K);
				for(int i=1;i<=Hcnt;++i)
					H[i].Sum+=(long long)(L[S[X].at].Both[i])*(long long)(K);
			}
		}
	}
	
	return 0;
}