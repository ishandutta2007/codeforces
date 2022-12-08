#include <iostream>
using namespace std;
const int MAXN=5555;
int N, ANScnt=0;
int Sum[MAXN][2], Key[MAXN], P[MAXN], A[MAXN], ANS[MAXN];
bool used[MAXN], fin;
void init(){
	for(int i=0;i<N;++i){
		used[i]=false;
		P[i]=-1;
	}
}
void TEST(){
	/*
	cout << "P: ";
	for(int i=0;i<N;++i)
		cout << P[i] << " ";
	cout << endl;
	cout << "A: ";
	for(int i=0;i<N;++i)
		cout << A[i] << " ";
	cout << endl;
	*/
	bool Win=true;
	for(int i=0;i<N;++i){
		if((P[i]^A[i])!=Sum[i][0]){
			//cout << i << endl;
			Win=false;
			break;
		}
	}
	if(!Win)	return;
	//cout << "PASS 1" << endl;
	for(int i=0;i<N;++i){
		if((P[i]^A[(i+1)%N])!=Sum[i][1]){
			//cout << i << endl;
			Win=false;
			break;
		}
	}
	if(!Win)	return;
	//cout << "PASS 2" << endl;
	for(int i=0;i<N;++i){
		if((P[i]^P[(i+1)%N])!=Key[i]){
			//cout << i << endl;
			Win=false;
			break;
		}
	}
	if(!Win)	return;
	//cout << "PASS 3" << endl;
	++ANScnt;
	for(int i=0;i<N;++i)
		ANS[i]=P[i];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=0;i<N;++i){
		cout << "? " << i << " " << i << endl;
		cin >> Sum[i][0];
	}
	for(int i=0;i<N;++i){
		cout << "? " << i << " " << (i+1)%N << endl;
		cin >> Sum[i][1];
	}
	for(int i=0;i<N;++i)
		Key[i]=Sum[i][1]^Sum[(i+1)%N][0];
	for(int k=0;k<N;++k){
		init();
		fin=true;
		for(int i=0, p=k;i<N;p=p^Key[i++]){
			if(p<0 || p>=N || used[p]){
				fin=false;
				break;
			}
			P[i]=p;
			A[p]=i;
			used[p]=true;
		}
		if(fin)	TEST();
	}
	cout << "!" << endl;
	cout << ANScnt << endl;
	for(int i=0;i<N;++i)
		cout << ANS[i] << " ";
	cout << endl;
	return 0;
}