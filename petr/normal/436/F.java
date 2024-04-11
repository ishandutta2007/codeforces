import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    static class User {
        int a;
        int b;
    }

    static final int STEP = 300;
    static final int MAX_PRICE = (int) 1e5 + 3;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int w = in.nextInt();
        User[] users = new User[n];
        int maxB = 0;
        for (int i = 0; i < n; ++i) {
            users[i] = new User();
            users[i].a = in.nextInt();
            users[i].b = in.nextInt();
            maxB = Math.max(maxB, users[i].b);
        }
        Arrays.sort(users, new Comparator<User>() {
            @Override
            public int compare(User o1, User o2) {
                return o1.b - o2.b;
            }
        });

        long[] value = new long[MAX_PRICE + 1];
        int[] sDelta = new int[MAX_PRICE + 1];
        long[] sFrom = new long[MAX_PRICE + 1];
        long[] answer = new long[n];
        long[] answerPrice = new long[n];
        int[] first = new int[MAX_PRICE + 1];
        for (int i = 0; i < n; i += STEP) {
            int[] price = new int[Math.min(n - i, STEP)];
            int[] delta = new int[price.length];
            for (int j = 0; j < price.length; ++j) {
                price[j] = users[i + j].a;
                delta[j] = 1;
            }
            int[] poi = Arrays.copyOf(price, price.length + 1);
            poi[price.length] = MAX_PRICE;
            Arrays.sort(poi);
            poi = ArrayUtils.unique(poi);
            int from = -1;
            long[] increments = new long[price.length];
            increments[0] = delta[0];
            for (int j = 1; j < increments.length; j++) {
                increments[j] = increments[j - 1] + delta[j];
            }
            int[] order = ArrayUtils.order(increments);
            int[] prOrder = ArrayUtils.order(price);
            int prIndex = 0;
            int[] newOrder = new int[order.length];
            for (int j = 0; j < poi.length; j++) {
                from++;
//				readInitSort -= System.currentTimeMillis();
                int to = poi[j];
                int sLength = 0;
                for (int k = from; k <= to; k++) {
                    while (sLength >= 2) {
                        long currentFrom = calculateFrom(value, sDelta[sLength - 1], k);
                        if (currentFrom <= sFrom[sLength - 1])
                            sLength--;
                        else
                            break;
                    }
                    sDelta[sLength] = k;
                    if (sLength == 0)
                        sFrom[sLength] = Long.MIN_VALUE;
                    else
                        sFrom[sLength] = calculateFrom(value, sDelta[sLength - 1], k);
                    sLength++;
                }
//				readInitSort += System.currentTimeMillis();
//				work -= System.currentTimeMillis();
                long total;
                int position = 0;
                for (int k = 0; k < price.length; k++) {
                    total = increments[order[k]];
                    while (position + 1 < sLength && sFrom[position + 1] <= total)
                        position++;
                    if (value[sDelta[position]] + sDelta[position] * total > answer[i + order[k]]) {
                        answer[i + order[k]] = value[sDelta[position]] + sDelta[position] * total;
                        answerPrice[i + order[k]] = sDelta[position];
                    }
                }
//				work += System.currentTimeMillis();
                from = poi[j];
//				postProcess -= System.currentTimeMillis();
                while (prIndex < price.length && price[prOrder[prIndex]] == poi[j]) {
                    int toRemove = prOrder[prIndex++];
                    for (int k = toRemove; k < increments.length; k++)
                        increments[k] -= delta[toRemove];
                    int fIndex = 0;
                    int sIndex = 0;
                    for (int k = 0; k < increments.length; k++) {
                        while (fIndex < increments.length && order[fIndex] >= toRemove)
                            fIndex++;
                        while (sIndex < increments.length && order[sIndex] < toRemove)
                            sIndex++;
                        if (fIndex == increments.length || sIndex != increments.length && increments[order[sIndex]] < increments[order[fIndex]])
                            newOrder[k] = order[sIndex++];
                        else
                            newOrder[k] = order[fIndex++];
                    }
                    int[] t = order;
                    order = newOrder;
                    newOrder = t;
                }
//				postProcess += System.currentTimeMillis();
            }
            Arrays.fill(first, -1);
            int[] next = new int[price.length];
            for (int j = 0; j < price.length; j++) {
                next[j] = first[price[j]];
                first[price[j]] = j;
            }
            long total = 0;
            for (int j = MAX_PRICE; j > 0; j--) {
                for (int k = first[j]; k != -1; k = next[k])
                    total += delta[k];
                value[j] += total * j;
            }
        }
        long[] res = new long[maxB + 2];
        long[] resPrice = new long[maxB + 2];
        for (int c = 0; c <= users[0].b; ++c) {
            res[c] = c * (long) w * (long) n;

        }
        for (int i = 0; i < users.length; ++i) {
            int minC = users[i].b + 1;
            int maxC = (i + 1 < users.length ? users[i + 1].b : maxB + 1);
            for (int c = minC; c <= maxC; ++c) {
                res[c] = (users.length - 1 - i) * (long) c * (long) w + answer[i];
                resPrice[c] = answerPrice[i];
            }
        }
        for (int i = 0; i <= maxB + 1; ++i) {
            out.println(res[i] + " " + resPrice[i]);
        }
    }

    private long calculateFrom(long[] value, int i, int k) {
        int lastDelta = i;
        int deltaDelta = k - lastDelta;
        long deltaValue = value[lastDelta] - value[k];
        long currentFrom;
        if (deltaValue >= 0)
            currentFrom = (deltaValue + deltaDelta - 1) / deltaDelta;
        else
            currentFrom = deltaValue / deltaDelta;
        return currentFrom;
    }
}

class ArrayUtils {

    public static int[] createOrder(int size) {
        int[] order = new int[size];
        for (int i = 0; i < size; i++)
            order[i] = i;
        return order;
    }

    public static int[] sort(int[] array, IntComparator comparator) {
        return sort(array, 0, array.length, comparator);
    }

    public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
        if (from == 0 && to == array.length)
            new IntArray(array).inPlaceSort(comparator);
        else
            new IntArray(array).subList(from, to).inPlaceSort(comparator);
        return array;
    }

    public static int[] order(final int[] array) {
        return sort(createOrder(array.length), new IntComparator() {
            public int compare(int first, int second) {
                if (array[first] < array[second])
                    return -1;
                if (array[first] > array[second])
                    return 1;
                return 0;
            }
        });
    }

    public static int[] order(final long[] array) {
        return sort(createOrder(array.length), new IntComparator() {
            public int compare(int first, int second) {
                if (array[first] < array[second])
                    return -1;
                if (array[first] > array[second])
                    return 1;
                return 0;
            }
        });
    }

    public static int[] unique(int[] array) {
        return unique(array, 0, array.length);
    }

    public static int[] unique(int[] array, int from, int to) {
        if (from == to)
            return new int[0];
        int count = 1;
        for (int i = from + 1; i < to; i++) {
            if (array[i] != array[i - 1])
                count++;
        }
        int[] result = new int[count];
        result[0] = array[from];
        int index = 1;
        for (int i = from + 1; i < to; i++) {
            if (array[i] != array[i - 1])
                result[index++] = array[i];
        }
        return result;
    }

}

abstract class IntCollection {
    public abstract IntIterator iterator();
    public abstract int size();

}

interface IntIterator {
    public int value() throws NoSuchElementException;
    /*
     * @throws NoSuchElementException only if iterator already invalid
     */
    public void advance() throws NoSuchElementException;
    public boolean isValid();
}

interface IntComparator {
    public static final IntComparator DEFAULT = new IntComparator() {
        public int compare(int first, int second) {
            if (first < second)
                return -1;
            if (first > second)
                return 1;
            return 0;
        }
    };

    public int compare(int first, int second);
}

abstract class IntList extends IntCollection implements Comparable<IntList> {
    private static final int INSERTION_THRESHOLD = 16;

    public abstract int get(int index);
    public abstract void set(int index, int value);

    public IntIterator iterator() {
        return new IntIterator() {
            private int size = size();
            private int index = 0;

            public int value() throws NoSuchElementException {
                if (!isValid())
                    throw new NoSuchElementException();
                return get(index);
            }

            public void advance() throws NoSuchElementException {
                if (!isValid())
                    throw new NoSuchElementException();
                index++;
            }

            public boolean isValid() {
                return index < size;
            }
        };
    }

    public IntList subList(final int from, final int to) {
        return new SubList(from, to);
    }

    private void swap(int first, int second) {
        if (first == second)
            return;
        int temp = get(first);
        set(first, get(second));
        set(second, temp);
    }

    public IntSortedList inPlaceSort(IntComparator comparator) {
        quickSort(0, size() - 1, (Integer.bitCount(Integer.highestOneBit(size()) - 1) * 5) >> 1, comparator);
        return new IntSortedArray(this, comparator);
    }

    private void quickSort(int from, int to, int remaining, IntComparator comparator) {
        if (to - from < INSERTION_THRESHOLD) {
            insertionSort(from, to, comparator);
            return;
        }
        if (remaining == 0) {
            heapSort(from, to, comparator);
            return;
        }
        remaining--;
        int pivotIndex = (from + to) >> 1;
        int pivot = get(pivotIndex);
        swap(pivotIndex, to);
        int storeIndex = from;
        int equalIndex = to;
        for (int i = from; i < equalIndex; i++) {
            int value = comparator.compare(get(i), pivot);
            if (value < 0)
                swap(storeIndex++, i);
            else if (value == 0)
                swap(--equalIndex, i--);
        }
        quickSort(from, storeIndex - 1, remaining, comparator);
        for (int i = equalIndex; i <= to; i++)
            swap(storeIndex++, i);
        quickSort(storeIndex, to, remaining, comparator);
    }

    private void heapSort(int from, int to, IntComparator comparator) {
        for (int i = (to + from - 1) >> 1; i >= from; i--)
            siftDown(i, to, comparator, from);
        for (int i = to; i > from; i--) {
            swap(from, i);
            siftDown(from, i - 1, comparator, from);
        }
    }

    private void siftDown(int start, int end, IntComparator comparator, int delta) {
        int value = get(start);
        while (true) {
            int child = ((start - delta) << 1) + 1 + delta;
            if (child > end)
                return;
            int childValue = get(child);
            if (child + 1 <= end) {
                int otherValue = get(child + 1);
                if (comparator.compare(otherValue, childValue) > 0) {
                    child++;
                    childValue = otherValue;
                }
            }
            if (comparator.compare(value, childValue) >= 0)
                return;
            swap(start, child);
            start = child;
        }
    }

    private void insertionSort(int from, int to, IntComparator comparator) {
        for (int i = from + 1; i <= to; i++) {
            int value = get(i);
            for (int j = i - 1; j >= from; j--) {
                if (comparator.compare(get(j), value) <= 0)
                    break;
                swap(j, j + 1);
            }
        }
    }

    public int hashCode() {
        int hashCode = 1;
        for (IntIterator i = iterator(); i.isValid(); i.advance())
            hashCode = 31 * hashCode + i.value();
        return hashCode;
    }

    public boolean equals(Object obj) {
        if (!(obj instanceof IntList))
            return false;
        IntList list = (IntList)obj;
        if (list.size() != size())
            return false;
        IntIterator i = iterator();
        IntIterator j = list.iterator();
        while (i.isValid()) {
            if (i.value() != j.value())
                return false;
            i.advance();
            j.advance();
        }
        return true;
    }

    public int compareTo(IntList o) {
        IntIterator i = iterator();
        IntIterator j = o.iterator();
        while (true) {
            if (i.isValid()) {
                if (j.isValid()) {
                    if (i.value() != j.value()) {
                        if (i.value() < j.value())
                            return -1;
                        else
                            return 1;
                    }
                } else
                    return 1;
            } else {
                if (j.isValid())
                    return -1;
                else
                    return 0;
            }
            i.advance();
            j.advance();
        }
    }

    private class SubList extends IntList {
        private final int to;
        private final int from;
        private int size;

        public SubList(int from, int to) {
            this.to = to;
            this.from = from;
            size = to - from;
        }

        public int get(int index) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            return IntList.this.get(index + from);
        }

        public void set(int index, int value) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            IntList.this.set(index + from, value);
        }

        public int size() {
            return size;
        }

    }
}

abstract class IntSortedList extends IntList {
    protected final IntComparator comparator;

    protected IntSortedList(IntComparator comparator) {
        this.comparator = comparator;
    }

    public void set(int index, int value) {
        throw new UnsupportedOperationException();
    }

    public IntSortedList inPlaceSort(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        throw new UnsupportedOperationException();
    }

    protected void ensureSorted() {
        int size = size();
        if (size == 0)
            return;
        int last = get(0);
        for (int i = 1; i < size; i++) {
            int current = get(i);
            if (comparator.compare(last, current) > 0)
                throw new IllegalArgumentException();
            last = current;
        }
    }

    public IntSortedList subList(final int from, final int to) {
        return new IntSortedList(comparator) {
            private int size = to - from;

            @Override
            public int get(int index) {
                if (index < 0 || index >= size)
                    throw new IndexOutOfBoundsException();
                return IntSortedList.this.get(index + from);
            }

            @Override
            public int size() {
                return size;
            }
        };
    }
}

class IntArray extends IntList {
    private final int[] array;

    public IntArray(int[] array) {
        this.array = array;
    }

    public IntArray(IntCollection collection) {
        array = new int[collection.size()];
        int i = 0;
        for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
            array[i++] = iterator.value();
    }

    public int get(int index) {
        return array[index];
    }

    public void set(int index, int value) {
        array[index] = value;
    }

    public int size() {
        return array.length;
    }

}

class IntSortedArray extends IntSortedList {
    private final int[] array;

    public IntSortedArray(int[] array) {
        this(array, IntComparator.DEFAULT);
    }

    public IntSortedArray(IntCollection collection) {
        this(collection, IntComparator.DEFAULT);
    }

    public IntSortedArray(int[] array, IntComparator comparator) {
        super(comparator);
        this.array = array;
        ensureSorted();
    }

    public IntSortedArray(IntCollection collection, IntComparator comparator) {
        super(comparator);
        array = new int[collection.size()];
        int i = 0;
        for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
            array[i++] = iterator.value();
        ensureSorted();
    }

    public int get(int index) {
        return array[index];
    }

    public int size() {
        return array.length;
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}