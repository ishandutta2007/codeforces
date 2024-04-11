private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    val ntest = readInt();
    repeat(ntest) {
        val n = readInt();

        class variableString {
            val hahaString = "haha";
            var count: Long = 0;
            val head = mutableListOf<Int>();
            val tail = mutableListOf<Int>();
            var headString: String = "";
            var tailString: String = "";

            fun initHead() {
                while(head.size < hahaString.length) head.add(0);
                for(i in 0..hahaString.length-1) head[i] = 0;
                if (headString.length > hahaString.length - 1) {
                    headString = headString.substring(0, hahaString.length - 1);
                }
                for(i in 0..headString.length-1) {
                    if(i < hahaString.length - 1 && headString.substring(0, i + 1) == hahaString.substring(hahaString.length - i - 1, hahaString.length)) {
                        head[i + 1] = 1;
                    }
                }
            }

            fun initTail() {
                while(tail.size < hahaString.length) tail.add(0);
                for(i in 0..hahaString.length-1) tail[i] = 0;

                if (tailString.length > hahaString.length - 1) {
                    tailString = tailString.substring(tailString.length - hahaString.length + 1, tailString.length);
                }
                for(i in 0..tailString.length-1) {
                    if(tailString.length - i < hahaString.length && tailString.substring(i, tailString.length) == hahaString.substring(0, tailString.length - i)) {
                        tail[tailString.length - i] = 1;
                    }
                }
            }

            fun initialize(initString: String) {
                repeat(hahaString.length) {
                    head.add(0);
                    tail.add(0);
                }
                headString = initString;
                tailString = initString;
                initHead();
                initTail();
                for(i in 0..initString.length-1) {
                    if (i + hahaString.length <= initString.length && initString.substring(i, i + hahaString.length) == hahaString) {
                        count = 1;
                    }
                }
            }

            constructor(initString: String) {
                initialize(initString);
            }
            constructor(lhs: variableString, rhs: variableString) {
                count = lhs.count + rhs.count;

                headString = lhs.headString + rhs.headString;
                tailString = lhs.tailString + rhs.tailString;


                initHead();
                initTail();

                for(i in 1..hahaString.length-1) {
                    if (lhs.tail[i] > 0 && rhs.head[hahaString.length - i] > 0) {
                        count += 1;
                    }
                }
            }
        };

        var ans: Long = 0;
        val myMap = mutableMapOf<String, variableString>();
        repeat(n) {
            val inputs = readStrings();
            if (inputs.size == 3){
                myMap.put(inputs[0], variableString(inputs[2]));
            }
            else {
                myMap.put(inputs[0], variableString(myMap[inputs[2]]?:variableString(""), myMap[inputs[4]]?:variableString("")));
            }
            ans = (myMap[inputs[0]]?:variableString("")).count;
        }
        println(ans);
    }
}