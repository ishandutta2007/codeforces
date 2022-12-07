import java.util.*

//region TEMPLATE
import java.io.*;
import java.io.BufferedReader
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    var (n, m) = readInts();
    var a = mutableListOf<String>();

    repeat(n) {
        var cur = readLn();
        a.add(cur);
    }

    var height = Array(n, {IntArray(m)});

    for(i in 0 until n){
        var row = IntArray(m);
        for(j in 0 until m){
            row[j] = 0;
        }
        height[i] = row;
    }
    var stack = mutableListOf<Int>();
    var stackSize = 0;

    repeat(m) {
        stack.add(0);
        stackSize += 1;
    }

    var left = mutableListOf<Int>();
    var right = mutableListOf<Int>();

    repeat(m) {
        left.add(-1);
        right.add(-1);
    }

    var answerForMask = mutableListOf<Long>();
    repeat(32) {
        answerForMask.add(0.toLong());
    }

    for(mask in 1..31) {
        var ans = 0.toLong();
        for(i in 0 until n) {
            for(j in 0 until m) {
                var id = a[i][j] - 'A';
                if (mask and (1 shl id) > 0) {
                    height[i][j] = 1;
                    if (i > 0) height[i][j] += height[i - 1][j];
                }
                else {
                    height[i][j] = 0;
                }
            }
        }

        for(i in 0 until n) {
            for(j in 0 until m){
                while(stackSize > 0 && height[i][j] <= height[i][stack[stackSize - 1]]) {
                    right[stack[stackSize - 1]] = j - 1;
                    stackSize -= 1;
                }
                if (stackSize > 0) {
                    left[j] = stack[stackSize - 1] + 1;
                }
                else {
                    left[j] = 0;
                }
                stack[stackSize] = j;
                stackSize++;
            }

            while(stackSize > 0) {
                right[stack[stackSize - 1]] = m - 1;
                stackSize -= 1;
            }

            for(j in 0..m-1) {
                if(height[i][j] > 0) {
                    ans += height[i][j].toLong() * (j - left[j] + 1).toLong() * (right[j] - j + 1);
                }
            }
        }

        answerForMask[mask] = ans;
    }

    var answerForLength = mutableListOf<Long>();
    repeat(5) {
        answerForLength.add(0.toLong());
    }
    for(mask in 31 downTo  1) {
        for(submask in 1 until mask) {
            if (mask and submask == submask) {
                if ((mask xor submask).countOneBits() % 2 == 0) answerForMask[mask] += answerForMask[submask];
                else answerForMask[mask] -= answerForMask[submask];
            }
        }

        answerForLength[mask.countOneBits() - 1] += answerForMask[mask];
    }

    println(answerForLength.joinToString(" "));
}