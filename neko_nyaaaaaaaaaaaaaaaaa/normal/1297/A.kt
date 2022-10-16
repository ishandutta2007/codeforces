import java.util.*
 
fun main() {
	val reader = Scanner(System.`in`)
	var t = reader.nextLine().toInt()
	
	repeat(t) {
		var n = reader.nextInt()
		
		if (n >= 999500) {
			if (n % 1000000 >= 500000) {
				print(n/1000000 + 1)
			} else {
				print(n/1000000)
			}
			print("M\n")
		} else if (n >= 1000) {
			if (n % 1000 >= 500) {
				print(n/1000 + 1)
			} else {
				print(n/1000)
			}
			print("K\n")
		} else {
			print(n)
			print("\n")
		}
	}
}