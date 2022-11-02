var
   a:array[1..1000] of longint;
    i,n:longint; may:boolean;



procedure prov(tek:longint;var may:boolean);
var i:longint;
 begin
  if (a[1]<tek) or (a[n]<tek)
   then
    begin
     may:=false;
     exit;
    end;
  for i:=2 to n-1 do
   if (a[i]<tek) and (a[i+1]<tek)
    then
     begin
      may:=false;
      exit;
     end;
  may:=true;
 end;


begin

  readln(n);
   for i:=1 to n do
  read(a[i]);

  for i:=1 to 1001 do
   begin
    prov(i,may);
     if may = false
      then
       begin
        writeln(i-1);
        halt;
       end;
   end;

end.