#include <iostream>
using namespace std;
int N;
int opr[13];
char o;
int v;
int ANS=0;
char ANSO[9];
int ANSV[9];
int main(){
	ios_base::sync_with_stdio(false);
	for(int i=0;i<10;++i)
		opr[i]=2;
	cin >> N;
	for(int i=1;i<=N;++i){
		cin >> o >> v;
		if(o=='|'){
			for(int j=0;j<10;++j){
				if((v>>j)&1){
					opr[j]=1;
				}
			}
		}
		if(o=='&'){
			for(int j=0;j<10;++j){
				if((v>>j)&1)	continue;
				opr[j]=-1;
			}
		}
		if(o=='^'){
			for(int j=0;j<10;++j){
				if((v>>j)&1){
					opr[j]=-opr[j];
				}
			}
		}
	}
	o='&';v=0;
	for(int i=0;i<10;++i){
		if(opr[i]==-1)	continue;
		v+=(1<<i);
	}
	if(v<((1<<10)-1)){
		++ANS;
		ANSO[ANS]=o;ANSV[ANS]=v;
	}
	o='|';v=0;
	for(int i=0;i<10;++i){
		if(opr[i]==1)	v+=(1<<i);
	}
	if(v>0){
		++ANS;
		ANSO[ANS]=o;ANSV[ANS]=v;
	}
	o='^';v=0;
	for(int i=0;i<10;++i){
		if(opr[i]==-2)	v+=(1<<i);
	}
	if(v>0){
		++ANS;
		ANSO[ANS]=o;ANSV[ANS]=v;
	}
	cout << ANS << endl;
	for(int i=1;i<=ANS;++i)
		cout << ANSO[i] << " " << ANSV[i] << endl;
	return 0;
}