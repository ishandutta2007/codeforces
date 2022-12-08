#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=100011;

int N;
int Num[MAXN];
int Pre[MAXN];
int In[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i)
		cin >> Num[i];
	
	sort(Num+1, Num+N+1);
	
	/*
	for(int i=1;i<=N;++i)
		cout << Num[i] << " ";
	cout << endl;
	*/
	
	for(int i=1, j=0;i<=N;++i){
		while(Num[j+1]<Num[i])	++j;
		Pre[i]=j;
	}
	
	/*
	for(int i=1;i<=N;++i)
		cout << Pre[i] << " ";
	cout << endl;
	*/
	
	for(int i=1;i<=N;++i)
		In[i]=Pre[i]-Pre[i-1];
	
	/*
	for(int i=1;i<=N;++i)
		cout << In[i] << " ";
	cout << endl;
	*/
	
	int Ans=0;
	
	for(int i=1, v=0;i<=N;++i){
		v+=In[i];
		if(v>0){
			++Ans;
			--v;
		}
	}
	
	cout << Ans << endl;
	
	return 0;
}