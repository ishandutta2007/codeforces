#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct dat{
    int x, y, z, i;
    dat(){}
    dat(int x, int y, int z, int i): x(x), y(y), z(z), i(i){}
    bool operator<(const dat &r)const{
        return make_pair(make_pair(x, y), make_pair(z, i)) < make_pair(make_pair(r.x, r.y), make_pair(r.z, r.i));
    }
};

int n;
dat arr[50002];
set<dat> st;

bool used[50002];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].z);
        arr[i].i = i;
        st.insert(arr[i]);
    }

    for(int cnt=0; cnt<n; cnt+=2){
        int i = st.begin()->i;
        st.erase(st.begin());

        auto tmp = *st.begin(); ///  x
        int tx = tmp.x;
        auto tmp2 = st.lower_bound(dat(tx, arr[i].y, -1e9, -10));
        if(tmp2 == st.end() || tmp2->x != tx) --tmp2;
        int ty = tmp2->y;
        assert(tmp2->x == tx);
        auto tmp3 = st.lower_bound(dat(tx, ty, arr[i].z, -10));
        if(tmp3 == st.end() || tmp3->x != tx || tmp3->y != ty) --tmp3;
        assert(tmp3->x == tx && tmp3->y == ty);

        printf("%d %d\n", arr[i].i, tmp3->i);
        st.erase(tmp3);
    }
    assert(st.empty());
}