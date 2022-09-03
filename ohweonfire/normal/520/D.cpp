#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Treap{
        struct node{
            int fix;
            T val;
            node *left=NULL;
            node *right=NULL;
        };
        private:
            node *root;
        public:
            void LeftRotate(node *&a)
            {
                node *b=a->right;
                a->right=b->left;
                b->left=a;
                a=b;
            }
            void RightRotate(node *&a)
            {
                node *b=a->left;
                a->left=b->right;
                b->right=a;
                a=b;
            }
            void insert(node *&p,int val)
            {
                if(!p)
                {
                    p=new node;
                    p->val=val;
                    p->fix=rand();
                }
                else
                {
                    if(val > p->val)
                    {
                        insert(p->right,val);
                        if(p->right->fix < p->fix)
                            LeftRotate(p);
                    }
                    else
                    {
                        insert(p->left,val);
                        if(p->left->fix < p->fix)
                            RightRotate(p);
                    }
                }
            }
            void insert(int a)
            {
                insert(root,a);
            }
            void del(node *&p,int val)
            {
                if(p->val==val)
                {
                    if(!p->right||!p->left)
                    {
                        node *t=p;
                        if(p->right!=NULL)
                            p=p->right;
                        else
                            p=p->left;
                        delete t;
                    }
                    else
                    {
                        if(p->left->fix < p->right->fix)
                        {
                            RightRotate(p);
                            del(p->right,val);
                        }
                        else
                        {
                            LeftRotate(p);
                            del(p->left,val);
                        }
                    }
                }
                else if(val<p->val)
                    del(p->left,val);
                else
                    del(p->right,val);
            }
            void del(int a)
            {
                del(root,a);
            }
            node* search(node *&p,int val)
            {
                if(!p)
                    return p;
                if(p->val==val)
                    return p;
                else if(p->val > val)
                    return search(p->left,val);
                else
                    return search(p->right,val);
            }
            node* search(int val)
            {
                return search(root,val);
            }
            int pmax(node *p)
            {
                while(p->left)
                    p=p->left;
                return p->val;
            }
            int Qmax()
            {
                return pmax(root);
            }
            int pmin(node *p)
            {
                while(p->right)
                    p=p->right;
                return p->val;
            }
            int Qmin()
            {
                return pmin(root);
            }
};
Treap<int> Tr;
int l[1300005],r[1300005],FLAG,s[1300005],key[1300005],root,X,Y,Z,o,n,i,sum,du[100005],xz[100005],j,k;
struct node {int x,y;} t[100005];
long long bit[100005],ans;
map <long long ,int> mp;
const int MOD=1000000009;
int main()
{
    srand((unsigned int)time(NULL));
    mp.clear();
    scanf("%d",&n);
    for (i=0; i<n; i++)
    {
        {scanf("%d%d",&t[i].x,&t[i].y);} swap(t[i].x,t[i].y);
        mp[(long long)t[i].x*2000000005+t[i].y]=i+1;
    }
    for (i=0; i<n; i++)
    {
        sum=0;
        if (mp[(long long)(t[i].x-1)*2000000005+t[i].y]) {sum++; X=mp[(long long)(t[i].x-1)*2000000005+t[i].y];}
        if (mp[(long long)(t[i].x-1)*2000000005+t[i].y-1]) {sum++;X=mp[(long long)(t[i].x-1)*2000000005+t[i].y-1];}
        if (mp[(long long)(t[i].x-1)*2000000005+t[i].y+1]) {sum++;X=mp[(long long)(t[i].x-1)*2000000005+t[i].y+1];}
        du[i]=sum;
        if (sum==1) xz[X-1]++;
    }
    for (i=0; i<n; i++) if (!xz[i]) {Tr.insert(i);}
    bit[0]=1;
    for (i=1; i<=n; i++) bit[i]=bit[i-1]*n%MOD; FLAG=1;
    for (i=n-1; i>=0; i--)
    {
        FLAG^=1;
        if (FLAG==1)X=Tr.Qmax(); else X=Tr.Qmin();
        ans=(ans+bit[i]*X)%MOD;
        mp[(long long )t[X].x*2000000005+t[X].y]=0;
        if (du[X]==1)
        {
            for (j=-1; j<=1; j++)
            {
                Y=mp[(long long)(t[X].x-1)*2000000005+t[X].y+j];
                if (Y)
                {
                    xz[Y-1]--;
                    if (xz[Y-1]==0) Tr.insert(Y-1);
                }
            }
        }
        for (j=-1; j<=1; j++)
        {
            Y=mp[(long long)(t[X].x+1)*2000000005+t[X].y+j];
            if (Y)
            {
                du[Y-1]--;
                if (du[Y-1]==1)
                {
                    for (k=-1; k<=1; k++)
                    {
                        Z=mp[(long long)(t[X].x)*2000000005+t[X].y+j+k];
                        if (Z)
                        {
                            xz[Z-1]++;
                            if (xz[Z-1]==1) Tr.del(Z-1);
                        }
                    }
                }
            }
        }
        Tr.del(X);
    }
    printf("%I64d\n",ans);
    return 0;
}