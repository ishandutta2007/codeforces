#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

struct SegmentString{
    vector<pair<char*, int> > seg;
    void insert(int pos, int size){
        FWD(i,0,(int)seg.size()){
            if(pos < seg[i].y){
                if(!pos){
                    seg.insert(seg.begin()+i, make_pair(new char[size], size));
                    return;
                }else{
                    seg.insert(seg.begin()+i+1, make_pair(seg[i].x+pos, seg[i].y-pos));
                    seg.insert(seg.begin()+i+1, make_pair(new char[size], size));
                    seg[i].y = pos;
                    return;
                }
            }else
                pos -= seg[i].y;
        }
        seg.push_back(make_pair(new char[size], size));
    }
    struct Iterator{
        vector<pair<char*, int> > *seg;
        int i, j;
        char& operator*(){
            return *((*seg)[i].x+j);
        }
        void operator++(){
            ++j;
            if((*seg)[i].y == j)
                ++i, j=0;
        }
        void move(int k){
            j += k;
            while((*seg)[i].y <= j){
                j -= (*seg)[i].y;
                ++i;
            }
        }
    };
    Iterator get(int pos){
        FWD(i,0,(int)seg.size())
            if(pos < seg[i].y)
                return Iterator({&seg, i, pos});
            else
                pos -= seg[i].y;
    }
};

SegmentString S;
int n;
char buff[3000010];
int L[5010];
int R[5010];
SegmentString::Iterator it;

void make(int i, int k){
    if(i == -1){
        S.insert(0, k);
        it = S.get(0);
        for(int i = 0; i < k; ++it, ++i)
            *it = buff[i];
        return;
    }
    int p = L[i];
    int q = R[i];
    if(q >= k-1){
        make(i-1, k);
        return;
    }
    int h;
    if(q+1+q-p+1 >= k)
        h = q+1;
    else
        h = k-(q-p+1);
    make(i-1, h);
    S.insert(q+1, min(q-p+1, k-h));
    it = S.get(q+1);
    SegmentString::Iterator sa = S.get(p+1);
    for(int i = 0; i < min(min(q-p+1, k-h), (q-p+1)/2); ++it, ++i){
        *it = *sa;
        sa.move(2);
    }
    sa = S.get(p);
    for(int i = (q-p+1)/2; i < min(q-p+1, k-h); ++it, ++i){
        *it = *sa;
        sa.move(2);
    }
}

int k;

int main(){
    scanf("%s", buff);
    scanf("%d", &k);
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d %d", &L[i], &R[i]);
        --L[i];
        --R[i];
    }
    make(n-1, k);
    it = S.get(0);
    for(int i = 0; i < k; ++it, ++i)
        buff[i] = *it;
    buff[k] = 0;
    printf("%s\n", buff);
    return 0;
}