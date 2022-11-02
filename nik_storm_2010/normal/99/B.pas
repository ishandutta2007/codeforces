program B99;
var
   n,i,koln,kolp,chin,chip,c,nomn,nomp : longint;
   a : array[1..1000] of longint;
   sum : int64;


Begin

 sum:=0;
  readln(n);
   for i:=1 to n do
    begin
     readln(a[i]);
      inc(sum,a[i]);
    end;

  c:=sum div n;
   if c*n <> sum
    then
     begin
      writeln('Unrecoverable configuration.');
       halt;
     end;
  koln:=0; kolp:=0; chin:=0; chip:=0;
   for i:=1 to n do
    begin

      if a[i] > c then begin inc(koln); inc(chin,abs(a[i]-c)); nomn:=i; end;
      if a[i] < c then begin inc(kolp); inc(chip,abs(a[i]-c)); nomp:=i; end;

    end;

  if (koln=0) and (kolp=0) then writeln('Exemplary pages.') else
   if (koln=1) and (kolp=1) and (chin=chip) then writeln(chin,' ml. from cup #',nomp,' to cup #',nomn,'.') else
    writeln('Unrecoverable configuration.');



End.