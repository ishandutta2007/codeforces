#include <bits/stdc++.h>
using namespace std;

struct Segment{
    int l;
    int r;
    long long val;
};

long long compute_val(Segment a, Segment b){
    long long res = ((long long)b.r - a.r + 1)*(b.r - b.l + 1);
    res += ((((long long)b.r - b.l + 2) + (a.r - a.l))*(a.r - a.l - b.r + b.l - 1)) / 2;

    if(a.r == -1){
        res = ((long long)b.l + 1)*(b.r - b.l + 1);
    }

    return res;
}

int main(){
    int n;
    int last_len = 0;;
    int cur = 0;
    long long sum = 0;
    cin >> n;

    string s;
    cin >> s;
    vector<Segment> v;
    Segment init;
    init.l = -1;
    init.r = -1;
    init.val = 0;
    v.push_back(init);

    for(int i = 0; i<n; i++){
        if(s[i] == '1'){
            if(i == 0 || s[i - 1] == '0'){
                Segment t;
                t.l = i;
                t.r = i;
                t.val = compute_val(v.back(), t);
                v.push_back(t);
            }

            else{
                Segment t = v.back();
                t.r = i;
                while(1){
                    Segment u = v[v.size() - 2];
                    if(u.r - u.l <= t.r - t.l && u.r != -1){
                        v.pop_back();
                        v.pop_back();
                        v.push_back(t);
                    }

                    else break;
                }

                t.val = compute_val(v[v.size() - 2], t);
                v[v.size() - 1] = t;
            }

            cur++;
            last_len = cur;
        }

        else{
            cur = 0;
        }

        for(auto x: v){
            sum += x.val;
            //cout << x.val << endl;
        }

        sum += ((long long)last_len*(last_len - 1)) / 2;
        //cout << endl;
        //cout << ((long long)last_len*(last_len - 1)) / 2 << endl;
        //cout << endl;
    }

    cout << sum;


}