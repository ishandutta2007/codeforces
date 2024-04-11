#include <bits/stdc++.h>
using namespace std;

const long long int M=1000000007;

long long int po(long long int a, int b){
    if(b==1) return a;

    long long int x=po(a, b/2);

    if((b%2)==0) return (x*x)%M;
    else return (((x*x)%M)*a)%M;
}

long long int gcd(long long int a, long long int b){
    while(a!=0 && b!=0){
        if(a>b){
            a=a%b;
        }

        else b=b%a;

    }

    return max(a, b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, l, r, x, y, type, pos, ska;
    vector<int> skap;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<long long int> seg;
    seg.resize(1048576);
    fill(seg.begin(), seg.end(), 0);

    for(int i=0; i<n; i++){
        seg[524288+1+i]=a[i];
    }

    for(int i=524287; i>0; i--){
        seg[i]=gcd(seg[2*i], seg[2*i+1]);
    }

    cin >> q;
    for(int i=0; i<q; i++){
        cin >> type;

        if(type==2){
            cin >> pos >> y;
            pos+=524288;
            seg[pos]=y;
            while(pos>0){
                pos/=2;
                seg[pos]=gcd(seg[2*pos], seg[2*pos+1]);
            }
        }

        else{
            skap.clear();
            ska=0;
            cin >> l >> r >> x;
            l--;
            l+=524288;
            r++;
            r+=524288;
            while(l<r-1){
                if(l%2==0){
                    if((seg[l+1]%x)!=0) skap.push_back(l+1);

                }

                if(r%2==1){
                    if((seg[r-1]%x)!=0) skap.push_back(r-1);

                }

                l/=2;
                r/=2;
            }

            if(skap.size()==0) cout << "YES" << endl;
            else if(skap.size()>=2) cout << "NO" << endl;
            else{
                y=skap[0];
                while(y<524288){
                    if(seg[2*y]%x==0) y=2*y+1;
                    else if(seg[2*y+1]%x==0) y=2*y;
                    else{
                        cout << "NO" << endl;
                        ska=1;
                        break;
                    }
                }

                if(ska==1) continue;
                cout << "YES" << endl;
            }

        }
    }



}