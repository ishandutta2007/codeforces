#include <iostream>
#include <set>
using namespace std;

int n,k,a;

set<int> ind;

int work(int x)
{
    return x/(a+1) + x%(a+1)/a;
}

int main()
{
    cin>>n>>k>>a;
    ind.insert(0); ind.insert(n+1);
    int i;
    int m;
    int cur_cnt=work(n);
    cin>>m;
    int l,r;
    int q;
    for(q=0;q<m;++q){
        cin>>i;
        if(ind.find(i)!=ind.end()) continue;
        auto it=ind.insert(i).first;
        
        --it;
        l=*it;
        ++it; ++it;
        r=*it;
        cur_cnt-=work(r-l-1);
        cur_cnt+=work(i-l-1);
        cur_cnt+=work(r-i-1);
        if(cur_cnt<k) break;
    }
    if(q==m) cout<<-1;
    else cout<<q+1;
    return 0;
}