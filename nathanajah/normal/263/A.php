<?php
$stdin = fopen('php://stdin', 'r');
function g() {
	global $stdin;
	return explode(" ", trim(fgets($stdin)));
}
$tmp;
$x;
$y;
for ($i=0;$i<5;++$i)
{
	$in=g();
	for ($j=0;$j<5;++$j)
	{
		$tmp=$in[$j];
		if ($tmp==1)
		{
			$x=$i;
			$y=$j;
		}
	}
}
$jarx=2-$x;
if ($jarx<0)
	$jarx=-$jarx;
$jary=2-$y;
if ($jary<0)
	$jary=-$jary;
echo $jarx+$jary;
?>