#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
    int x, y, a, b;
    cin>>x>>y>>a>>b;
    vector<pair<int,int> >v;
    for (int i=a; i<=x; i++) {
	for (int j=b; j<=y; j++) {
	    if (i>j) v.push_back(make_pair(i, j));
	}
    }
    sort(v.begin(), v.end());
    cout<<v.size()<<endl;
    for (int i=0; i<int(v.size()); i++) {
	printf("%d %d\n", v[i].first, v[i].second);
    }

    return 0;
}