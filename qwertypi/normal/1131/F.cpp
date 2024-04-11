#include <iostream>
#include <vector>
using namespace std;

int Size[150000];
int Parent[150000];
vector<vector<int>> Kitten(150000);

int root(int A){
	while(A != Parent[A]){
		Parent[A] = Parent[Parent[A]];
		A = Parent[A];
	}
	return A;
}

void Union(int A, int B){
	int root_A = root(A);
	int root_B = root(B);
	if(Size[root_A] <= Size[root_B]){
		Kitten[root_B].insert(Kitten[root_B].begin() + Size[root_B], Kitten[root_A].begin(), Kitten[root_A].end());
		Kitten[root_A].resize(0);
		Size[root_B] += Size[root_A];
		Size[root_A] = 0;
		Parent[root_A] = root_B;
	}else{
		Kitten[root_A].insert(Kitten[root_A].begin() + Size[root_A], Kitten[root_B].begin(), Kitten[root_B].end());
		Kitten[root_B].resize(0);
		Size[root_A] += Size[root_B];
		Size[root_B] = 0;
		Parent[root_B] = root_A;
	}
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		Parent[i] = i;
		Size[i] = 1;
		Kitten[i].push_back(i);
	}
	for(int i=0;i<n-1;i++){
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		Union(v1, v2);
	}
	for(int i=0;i<n;i++){
		if(Parent[i] == i){
			for(auto j:Kitten[i]){
				cout << j + 1 << ' ';
			}
			break;
		}
	}
	return 0;
}