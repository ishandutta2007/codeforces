
namespace Solution {
open Microsoft.Quantum.Primitive;
open Microsoft.Quantum.Canon;

function FindFirstDiff (bits0 : Bool[], bits1 : Bool[]) : Int
{
for (i in 0 .. Length(bits1)-1) {
if (bits0[i] != bits1[i]) {
return i;
}
}
return -1;
}
operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int

{
// find the first index at which the bitstrings are different and measure it
let firstDiff = FindFirstDiff(bits0, bits1);
let res = (M(qs[firstDiff]) == One);
if (res == bits0[firstDiff]) {
return 0;
} else {
return 1;
}
}
}