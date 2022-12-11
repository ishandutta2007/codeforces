//package Application;
import java.lang.Math;
import java.io.BufferedReader;
import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.io.IOException;
public class Application {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(
                                new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        if(n==0)System.out.print("zero");
        switch (n/10) {
            case 1:
                switch (n%10) {
                    case 1:
                        System.out.print("eleven");
                        break;
                    case 2:
                        System.out.print("twelve");
                        break;
                    case 3:
                        System.out.print("thirteen");
                        break;
                    case 4:
                        System.out.print("fourteen");
                        break;
                    case 5:
                        System.out.print("fifteen");
                        break;
                    case 6:
                        System.out.print("sixteen");
                        break;
                    case 7:
                        System.out.print("seventeen");
                        break;
                    case 8:
                        System.out.print("eighteen");
                        break;
                    case 9:
                        System.out.print("nineteen");
                        break;
                    case 0:
                        System.out.print("ten");
                        break;
                }   break;
            case 2:
                System.out.print("twenty");
                break;
            case 3:
                System.out.print("thirty");
                break;
            case 4:
                System.out.print("forty");
                break;
            case 5:
                System.out.print("fifty");
                break;
            case 6:
                System.out.print("sixty");
                break;
            case 7:
                System.out.print("seventy");
                break;
            case 8:
                System.out.print("eighty");
                break;
            case 9:
                System.out.print("ninety");
                break;
            default:
                break;
        }
        if(n/10>1 && n%10>0){
            System.out.print("-");
        }
        if((n/10)!=1)
        switch(n%10){
            case 1:
                System.out.print("one");
                break;
            case 2:
                System.out.print("two");
                break;
            case 3:
                System.out.print("three");
                break;
            case 4:
                System.out.print("four");
                break;
            case 5:
                System.out.print("five");
                break;
            case 6:
                System.out.print("six");
                break;
            case 7:
                System.out.print("seven");
                break;
            case 8:
                System.out.print("eight");
                break;
            case 9:
                System.out.print("nine");
                break;
        }
    }
}