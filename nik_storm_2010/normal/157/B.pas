var
   a : array[1..200] of longint;
    pred, tek, answer : extended;
     color:string;
    i,n : longint;


procedure BubbleSort;
var i,j,tmp:longint;
 begin
  for i:=1 to n do
   for j:=i+1 to n do
    if a[i]>a[j]
   then
    begin
     tmp:=a[i];
      a[i]:=a[j];
     a[j]:=tmp;
    end;
 end;


begin

  readln(n);
   for i:=1 to n do read(a[i]);
  BubbleSort;

  if n mod 2 = 1 then color:='red' else color:='blue'; pred:=0; answer:=0;
   for i:=1 to n do
    begin
     tek:=Pi * (a[i]*a[i]);
      if color = 'red'
       then
        begin
         answer:=answer + tek - pred;
          color:='blue';
         pred:=tek;
        end
       else
        begin
        color:='red';
        pred:=tek;
        end;
    end;
  writeln(answer:0:5);

end.