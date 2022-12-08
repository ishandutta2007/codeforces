#include <iostream>

using namespace std;

const int MAXN=1011;

int N;
int Next[MAXN];
int Vis[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i=1;i<=N;++i)	cin >> Next[i];
	
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j)	Vis[j]=0;
		for(int j=i;;j=Next[j]){
			++Vis[j];
			if(Vis[j]>1){
				cout << j << " ";
				break;
			}
		}
	}
	cout << endl;
	
	return 0;
}