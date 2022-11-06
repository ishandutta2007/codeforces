#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int left, right, mx;

    Node(int l, int r, int m)
    {
        left = l;
        right = r;
        mx = m;
    }
};

const int MAXN = 1 << 19;
int a[MAXN];
int before[MAXN];
vector<Node> tree;
int roots[MAXN];

int buildTree(int l = 0, int r = MAXN - 1)
{
    if (l == r)
        tree.push_back(Node(-1, -1, 0));
    else
    {
        int mid = (l + r) / 2;
        int leftInd = buildTree(l, mid);
        int rightInd = buildTree(l, mid);
        tree.push_back(Node(leftInd, rightInd, 0));
    }
    return (int) tree.size() - 1;
}

int upd(int ind, int pos, int num, int l = 0, int r = MAXN - 1)
{
    if (l == r)
        tree.push_back(Node(-1, -1, num));
    else
    {
        int mid = (l + r) / 2;
        int leftInd = tree[ind].left;
        int rightInd = tree[ind].right;
        if (pos <= mid)
            leftInd = upd(leftInd, pos, num, l, mid);
        else
            rightInd = upd(rightInd, pos, num, mid + 1, r);
        tree.push_back(Node(leftInd, rightInd, max(tree[leftInd].mx, tree[rightInd].mx)));
        //cout << "setting max of " << l << " " << r << " to " << tree.back().mx << endl;
    }
    return (int) tree.size() - 1;
}

int query(int ind, int lquery, int rquery, int l = 0, int r = MAXN - 1)
{
    if (l > rquery || r < lquery)
        return 0;
    //cout << "this is " << tree[ind].mx << endl;
    if (l >= lquery && r <= rquery)
        return tree[ind].mx;
    int mid = (l + r) / 2;
    return max(query(tree[ind].left, lquery, rquery, l, mid), query(tree[ind].right, lquery, rquery, mid + 1, r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        tree.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        stack<int> st;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && a[i] >= a[st.top()])
            {
                before[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            before[st.top()] = -1;
            st.pop();
        }
        /*
        for (int i = 0; i < n; i++)
        {
            cout << "before " << i << " " << before[i] << endl;
        }
        */
        int two = 1 << (32 - __builtin_clz(n));
        int r = buildTree(0, two - 1);
        roots[0] = upd(r, a[0], 1, 0, two - 1);
        for (int i = 1; i < n; i++)
        {
            int best = 1 + query(roots[i - 1], 0, a[i], 0, two - 1);
            if (before[i] != -1)
            {
                if (before[i])
                    best = max(best, 2 + query(roots[before[i] - 1], 0, a[i], 0, two - 1));
                else
                    best = max(best, 2);
            }
            roots[i] = upd(roots[i - 1], a[i], best, 0, two - 1);
        }
        int ans = 1;
        int biggest = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans = max(ans, query(roots[i], a[i], a[i], 0, two - 1) + (biggest >= a[i]));
            biggest = max(biggest, a[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}