#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <complex>
#include <functional>
#include <queue>
#include <set>
#include <random>
#include <map>
#include <bitset>

#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cassert>

#define nodeptr node *

#pragma warning (disable : 4018)
#pragma warning (disable : 4244)
#pragma comment (linker, "/STACK:200000000")

using namespace std;

mt19937 mt (time (NULL));

class treap
{
    class node
    {
    public:
        int val, siz;
        long long sum;
        nodeptr l;
        nodeptr r;
        bool virt;

        node (nodeptr l, nodeptr r) : l (l), r (r), virt (true), sum (get_sum (l) + get_sum (r)),
            val (0), siz (get_size (l) + get_size (r))
        {}

        node (int val, nodeptr l, nodeptr r) : l (l), r (r), virt (false), sum (get_sum (l) + val + get_sum (r)),
            val (val), siz (get_size (l) + 1 + get_size (r))
        {}

        static int get_size (const nodeptr v)
        {
            return v == NULL ? 0 : v->siz;
        }

        static int get_val (const nodeptr v)
        {
            return v == NULL ? 0 : v->val;
        }

        static long long get_sum (const nodeptr v)
        {
            return v == NULL ? 0 : v->sum;
        }

        static nodeptr merge (nodeptr left, nodeptr right)
        {
            if (left == NULL)
                return right;
            if (right == NULL)
                return left;

            if (mt () % (get_size (left) + get_size (right)) < get_size (left))
                return new node (left->val, left->l, merge (left->r, right));
            else
                return new node (right->val, merge (left, right->l), right->r);
        }

        void split (nodeptr &left, nodeptr &right, int pos)
        {
            if (pos <= get_size (l))
            {
                if (virt)
                    right = new node (NULL, r);
                else
                    right = new node (val, NULL, r);

                if (l != NULL)
                    l->split (left, right->l, pos);
            }
            else
            {
                if (virt)
                    left = new node (l, NULL);
                else
                    left = new node (val, l, NULL);

                if (r != NULL)
                    r->split (left->r, right, pos - get_size (l) - (virt ? 0 : 1));
            }
        }

        long long seg (int le, int ri) const
        {
            if (le >= siz || ri <= 0)
                return 0;
            if (le <= 0 && siz <= ri)
                return sum;

            return (l == NULL ? 0 : l->seg (le, ri)) + val + (r == NULL ? 0 : r->seg (le, ri));
        }
    };

    nodeptr grow (nodeptr v, int n)
    {
        if (n == 1)
            return v;
        return new node (grow (v, n / 2), grow (v, (n + 1) / 2));
    }

    nodeptr build (const vector<int> &arr, int l, int r)
    {
        if (r <= l)
            return NULL;

        int t = (l + r) / 2;

        return new node (arr[t], build (arr, l, t), build (arr, t + 1, r));
    }
};

void dfs (const vector<vector<pair<int, pair<int, int>>>> &gr, vector<int> &used, int st = 0)
{
    if (!used[st])
    {
        used[st] = true;

        for (auto it : gr[st])
            dfs (gr, used, it.first);
    }
}

void build (vector<vector<pair<int, int>>> &gr, vector<int> p)
{
    for (int st = 0; st < gr.size (); st++)
    {
        vector<int> parts (p.size ());

        int t = st;

        for (auto &it : parts)
        {
            it = t % 7;
            t /= 7;
        }

        for (auto it : p)
        {
            vector<int> to (parts.size ());

            to[0] = max ({parts[0], parts[1]});
            to.back () = max ({parts[parts.size () - 2], parts.back ()});

            for (int i = 1; i < to.size () - 1; i++)
                to[i] = max ({parts[i - 1], parts[i], parts[i + 1]});

            parts[it]++;

            int k = *min_element (to.begin (), to.end ());

            for (auto &it : to)
                it -= k;

            reverse (to.begin (), to.end ());

            int w = 0;

            for (auto it : to)
            {
                w *= 7;
                w += it;
            }

            gr[st].push_back ({w, k});
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    string s;
    int n;

    cin >> s >> n;

    set<char> chars (s.begin (), s.end ());

    if (n > s.size ())
        cout << "impossible" << endl;
    else
        cout << max (n - (int)chars.size (), 0) << endl;

    return 0;
}