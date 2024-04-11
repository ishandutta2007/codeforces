import java.util.*
 
fun main() {
	val reader = Scanner(System.`in`)
	var t = reader.nextLine().toInt()
	
	repeat(t) {
		var n = reader.nextInt()
		var k = reader.nextInt()
		
		var pfk = k*k*k + k*k + k + 1
		print(n/pfk)
		print(' ')
		
		print(n/pfk * k)
		print(' ')
		
		print(n/pfk * k * k)
		print(' ')
		
		print(n/pfk * k * k * k)
		print('\n')
	}
}