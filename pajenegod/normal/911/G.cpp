#include <vector>
#include <iostream>
using namespace std;

class operation_query
{
public:
    int A[100];
    int l,r;
    int uses;

    operation_query(int l,int r): l(l),r(r),uses(0)
    {
        for (int i=0; i<100;++i)
            A[i]=i;
    };
    
    operation_query(operation_query *q1, operation_query *q2): uses(0)
    {
        l = q1->l;
        r = q1->r;
        for (int i=0; i<100;++i)
            A[i]=q2->A[q1->A[i]];
    };
};

operation_query* merge(operation_query *q1, operation_query *q2)
{
    operation_query *q = new operation_query(q1->l,q1->r);
    for (int i=0; i<100; ++i)
    {
        q->A[i] = q2->A[q1->A[i]];
    }
    return q;
}

class read_query
{
public:
    int l,r;
    read_query(int l, int r): l(l), r(r)
    {
    }
};

class LazySeg
{
public:
    void apply_query(operation_query *q)
    {
        if (q->l <= l && r <= q->r)
        {
            if (r-l==1)
            {
                val = q->A[val];
            } else
            {
                if (this->q!=NULL) 
                {
                    operation_query *newq = new operation_query(this->q,q);
                    this->q->uses-=1;
                    if (this->q->uses==0)
                        delete this->q;
                    this->q = newq;
                    this->q->uses += 1;
                }
                else 
                {
                    this->q = q;
                    q->uses += 1;
                }
            }
        } else if (q->l < r && l < q->r)
        {
            push_query();
            this->q = q;
            q->uses += 1;
            push_query();
        }
    }
    int read_query(int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return val;
        } else if (ql < r && l < qr)
        {
            push_query();
            int a,b;
            a = lnode->read_query(ql,qr);
            if (a!=-1) return a;
            return rnode->read_query(ql,qr);
        }
        return -1;
    }

    void push_query()
    {
        if (lnode==NULL)
        {
            int mid = (l+r)/2;
            lnode = new LazySeg(l,mid,A);
            rnode = new LazySeg(mid,r,A);
        }
        if (q!=NULL)
        {
            lnode->apply_query(q);
            rnode->apply_query(q);
            q->uses-=1;
            if (q->uses==0)
                delete q;
            q = NULL;
        }
    }
    

    int l,r;
    int val;
    vector<int> *A;
    LazySeg *lnode, *rnode;
    operation_query* q;
    LazySeg(int l,int r, vector<int> *A):l(l),r(r),A(A)
    {
        q = NULL;
        lnode=NULL;
        rnode=NULL;
        if (r-l==1)
            val = (*A)[l];
        else
            val = -1;
    }

};




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;++i)
    {
        cin >> A[i];
        --A[i];
    }
    
    LazySeg sup(0,n,&A);

    int m;
    cin >> m;
    for (int i=0; i<m; ++i)
    {
        int l,r,x,y;
        cin >> l >> r >> x >> y;
        --l;--x;--y;
        operation_query *q = new operation_query(l,r);
        q->A[x]=y;
        sup.apply_query(q);
    }
    for (int i=0; i<n; ++i)
    {
        cout << sup.read_query(i,i+1)+1 << " ";
    }
    return 0;
}