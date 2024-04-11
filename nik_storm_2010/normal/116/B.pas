Program B116;
Var
  a : array[0..11,0..11] of char;
  n,m,i,j,answer : longint;


procedure inputdata;
var i,j:longint;
 begin
  readln(n,m);
   for i:=1 to n do
    begin
     for j:=1 to m do read(a[i,j]);
      readln;
    end;
 end;


procedure outputdata;
 begin
  writeln(answer);
 end;


Begin

  inputdata;
   answer:=0;
    for i:=1 to n do
     for j:=1 to m do
      if a[i,j]='W'
       then
        begin
         if (a[i,j-1]='P') then begin inc(answer); a[i,j-1]:='.'; end else
          if (a[i,j+1]='P') then begin inc(answer); a[i,j+1]:='.'; end else
           if (a[i+1,j]='P') then begin inc(answer); a[i+1,j]:='.'; end else
            if (a[i-1,j]='P') then begin inc(answer); a[i-1,j]:='.'; end;
        end;
   outputdata;

End.