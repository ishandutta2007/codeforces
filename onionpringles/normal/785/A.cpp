#include  <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> s = {"Tetrahedron","Cube","Octahedron","Dodecahedron","Icosahedron"};
int m[5]={4,6,8,12,20};
int main(){
	ios::sync_with_stdio(0);
	int n;cin>>n;
	int ans=0;
	for(int i=0;i<n;i++){
		string foo;
		cin>>foo;
		ans += m[find(s.begin(),s.end(),foo)-s.begin()];
	}
	cout << ans << endl;
	
}