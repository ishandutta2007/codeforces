#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main()
{
    int n;
    cin >> n;
    deque<int>c;
    int sk;
    for(int i = 0;i<n;i++){
        cin >> sk;
        c.push_back(sk);
    }
    int s1,s2;
    s1 = 0;
    s2 = 0;
    bool mov_e = false;
    while(c.size()>0){
        if(mov_e == false){
            if(c.front() > c.back()){
                s1 += c.front();
                c.pop_front();
            }
            else{
                s1 += c.back();
                c.pop_back();
            }
            mov_e = true;
        }
        else{
            if(c.front() > c.back()){
                s2 += c.front();
                c.pop_front();
            }
            else{
                s2 += c.back();
                c.pop_back();
            }
            mov_e = false;
        }
    }
    cout << s1 << " " << s2;
    return 0;
}