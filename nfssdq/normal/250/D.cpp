#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <locale>
#include <iterator>
#include <valarray>
#include <complex>
using namespace std;
#define LL long long
int n, m;
long long l, r;
vector<long long> a;
vector<pair<long long,long long> >b;
double dis(int ia, int ib)
{
    return sqrt(l*l+a[ia]*a[ia])+sqrt((r-l)*(r-l)+(b[ib].first-a[ia])*(b[ib].first-a[ia]))+b[ib].second;
}
void update(int ia, int ib, int &resa, int &resb){
    if(dis(ia,ib)<dis(resa,resb))
    {
        resa=ia;
        resb=ib;
    }
}
void input(){
    cin>>n>>m>>l>>r;
    a.resize(n);
    b.resize(m);
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<m; i++)cin>>b[i].first;
    for(int i=0; i<m; i++)cin>>b[i].second;
}
void solve(){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int resa=0, resb=0;
    for(int i=0; i<m; i++){
        double bb=double(b[i].first)*l/r;
        int ii=lower_bound(a.begin(), a.end(), bb)-a.begin();
        update(ii, i, resa,resb);
        if(0<ii)
            update(ii-1, i, resa,resb);
        if(ii<a.size()-1)
            update(ii+1, i, resa,resb);
    }
    cout<<resa+1<<" "<<resb+1<<endl;
}
int main() {
	input();
	solve();
}