#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>p, m, z;
int n,t;
void out(vector<int>&a) {
    printf("%d", a.size());
    for (int i=0; i<int(a.size()); i++) printf(" %d", a[i]);
    puts("");

}
int main() {
    
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
	scanf("%d", &t);
	if (t==0) z.push_back(t);
	if (t<0) m.push_back(t);
	if (t>0) p.push_back(t);
    }
    if (p.size()==0) {
	p.push_back(m.back()); m.pop_back();
	p.push_back(m.back()); m.pop_back();
    }
    if (m.size()%2==0) {
	z.push_back(m.back()); m.pop_back();
    }

    out(m);
    out(p);
    out(z);
    return 0;
}