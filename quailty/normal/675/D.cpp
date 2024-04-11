#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int INF=0x3f3f3f3f;
set<pair<int,int> >st;
int main()
{
    int n;
    scanf("%d",&n);
    int rt;
    scanf("%d",&rt);
    st.insert(make_pair(rt,-rt));
    st.insert(make_pair(INF,rt));
    for(int i=1;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        auto itr=st.lower_bound(make_pair(a,0));
        printf("%d ",abs(itr->second));
        int l=itr->first;
        st.erase(itr);
        st.insert(make_pair(l,a));
        st.insert(make_pair(a,-a));
    }
    return 0;
}