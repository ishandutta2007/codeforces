#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int a , b , c;
int val;
multiset < int > s;
int ans = 0;
void sortt(){
    if(a > b){
        swap(a , b);
    }
    if(a > c){
        swap(a , c);
    }
    if(b > c){
        swap(b , c);
    }
}
int main(){
    scanf("%d" , &n);
    scanf("%d %d %d" , &a , &b , &c);
    sortt();
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &val);
        if(val > a + b + c){
            printf("-1\n");
            return 0;
        }
        s.insert(val);
    }
    //a + b + c se chote and b + c se bade
    while(!s.empty()){
        auto it = s.lower_bound(b + c + 1);
        if(it == s.end()){
            break;
        }
        s.erase(it);
        ++ans;
    }
    //b + c se chote and a + c se bade along with a se chote
    while(!s.empty()){
        auto it = s.lower_bound(a + c + 1);
        if(it == s.end()){
            break;
        }
        s.erase(it);
        it = s.lower_bound(a + 1);
        if(it != s.begin()){
            --it;
            s.erase(it);
        }
        ++ans;
    }
    //a + c se chote and max(c , a + b) se bade along with b se chote
    while(!s.empty()){
        auto it = s.lower_bound(max(c , a + b) + 1);
        if(it == s.end()){
            break;
        }
        s.erase(it);
        it = s.lower_bound(b + 1);
        if(it != s.begin()){
            --it;
            s.erase(it);
        }
        ++ans;
    }
    if(a + b > c){
        //a + b se chote and c se bade along with c se chote
        while(!s.empty()){
            auto it = s.lower_bound(c + 1);
            if(it == s.end()){
                break;
            }
            s.erase(it);
            it = s.lower_bound(c + 1);
            if(it != s.begin()){
                --it;
                s.erase(it);
            }
            ++ans;
        }
    }
    //a , b , c individually
    while(!s.empty() && (*s.begin() <= a)){
        auto it = s.lower_bound(c + 1);
        if(it != s.begin()){
            --it;
            s.erase(it);
        }
        it = s.lower_bound(b + 1);
        if(it != s.begin()){
            --it;
            s.erase(it);
        }
        it = s.lower_bound(a + 1);
        if(it != s.begin()){
            --it;
            s.erase(it);
        }
        ++ans;
    }
    //a + b se chote along with c se chote
    //ans += ceil(1.0 * (int(s.size())) / 2.0);
    while(!s.empty()){
        s.erase(prev(s.end()));
        auto it = s.lower_bound(a + b + 1);
        if(it != s.begin()){
            --it;
            s.erase(it);
        }
        ++ans;
    }
    //assert(s.empty());
    cout << ans;
}