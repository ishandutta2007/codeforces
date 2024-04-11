<?php
$stdin = fopen('php://stdin', 'r');
function g() {
	global $stdin;
	return explode(" ", trim(fgets($stdin)));
}
$in=g();
$n=$in[0];
$k=$in[1];
$arr=g();
for ($i=0;$i<$n;++$i)
	for ($j=0;$j<$n-1;++$j)
	{
		if ($arr[$j]>$arr[$j+1])
		{
			$tmp=$arr[$j];
			$arr[$j]=$arr[$j+1];
			$arr[$j+1]=$tmp;
		}
	}
$i=$n-1;
$sum=0;
while ($i>=0)
{
	$j=$i;
	while ($arr[$j]==$arr[$i])
	{
		++$sum;
		--$j;
		if ($j==-1)
			break;
	}
	$i=$j;
	if ($sum==$k)
		break;
}
if ($sum==$k)
	echo $arr[$i+1]." ".$arr[$i+1];
else
	echo -1;
?>